/*
 * Copyright (C) 2014 TopCoder Inc., All Rights Reserved.
 */
package lockscreen.poc;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.bluetooth.DeviceClass;
import javax.bluetooth.DiscoveryAgent;
import javax.bluetooth.DiscoveryListener;
import javax.bluetooth.LocalDevice;
import javax.bluetooth.RemoteDevice;
import javax.bluetooth.ServiceRecord;
import javax.swing.DefaultListModel;
import javax.swing.JComboBox;
import javax.swing.SwingWorker;

import org.apache.log4j.Logger;

import com.intel.bluetooth.RemoteDeviceHelper;

/**
 * Represents background task to search bluetooth devices,if found paired device
 * is disconnected then just lock screen.
 * <p>
 * <strong>Thread Safety: </strong> This class is immutable and thread safe.
 * </p>
 * 
 * @author TCSASSEMLBER
 * @version 1.0
 */
public final class BTDeviceDiscoveryTask extends
        SwingWorker<List<RemoteDevice>, Void> implements DiscoveryListener {
    /**
     * Represents the finish refresh devices message.
     */
    private static final String FINISH_REFRESH_DEVICES_MESSAGE = "Finish to refresh bluetooth devices!";
    
    /**
     * Represents the failed devices map, the key is device address the value is
     * failed times,if device fails to connect after configured times it will lock screen,
     * it will reset failed times after it can connect successfully once or lock screen successfully.
     */
    private static final Map<String, Integer> FAILED_DEVICES = new HashMap<String, Integer>();

    /**
     * Represents the logger.
     */
    private static final Logger LOG = Logger
            .getLogger(BTDeviceDiscoveryTask.class);
    /**
     * Represents the object to check lock.
     */
    private static Object lock = new Object();

    /**
     * Represents the remote bluetooth devices.
     */
    private List<RemoteDevice> devices;

    /**
     * Represents the main frame.
     */
    private MainFrame mainFrame;

    /**
     * Creates an instance of this class.
     * 
     * @param mainFrame
     *            the main frame.
     */
    public BTDeviceDiscoveryTask(MainFrame mainFrame) {
        devices = new ArrayList<RemoteDevice>();
        this.mainFrame = mainFrame;
    }

    /**
     * Background task to get remote bluetooth devices.
     * 
     * @return remote bluetooth devices.
     * @throws Exception
     *             throws if any error happen.
     */
    @Override
    protected List<RemoteDevice> doInBackground() throws Exception {
        devices.clear();
        try {
            LocalDevice localDevice = LocalDevice.getLocalDevice();
            DiscoveryAgent agent = localDevice.getDiscoveryAgent();
            agent.startInquiry(DiscoveryAgent.GIAC, this);
            try {
                synchronized (lock) {
                    lock.wait();
                }
            } catch (InterruptedException e) {
                LOG.error("Error when startting inquiry devices", e);
                return devices;
            }
        } catch (Exception e) {
            LOG.error("Error when getting bluetooth remote devices", e);
            throw e;
        }
        return devices;
    }

    /**
     * Render device list when getting all bluetooth remote devices,if selected
     * paired device is disconnected just lock screen.
     */
    @Override
    protected void done() {
        super.done();
        DefaultListModel defaultModel = mainFrame.getModel();
        defaultModel.clear();
        boolean exist = false;
        String pairingDeviceAddress = null;
        RemoteDevice pairingDevice = null;
        JComboBox deviceComboBox = mainFrame.getDeviceComboBox();
        if (deviceComboBox.getSelectedItem() != null
                && deviceComboBox.getSelectedItem() instanceof RemoteDevice) {
            pairingDevice = (RemoteDevice) deviceComboBox.getSelectedItem();
            pairingDeviceAddress = pairingDevice.getBluetoothAddress();
        }
        for (RemoteDevice device : devices) {
            if (device.getBluetoothAddress().equals(pairingDeviceAddress)) {
                exist = true;
            }
            defaultModel.addElement(device);
        }
        if (mainFrame.getLockCheckBox().isSelected()) {
            if (pairingDeviceAddress != null) {
                try {
                    String deviceName = pairingDevice.getFriendlyName(false);
                    if (exist
                            && RemoteDeviceHelper.authenticate(pairingDevice,
                                    mainFrame.getPin())) {
                        LOG.debug("Find and authenticate device "
                                + deviceName+" successfully!");
                        if (FAILED_DEVICES.containsKey(pairingDeviceAddress)) {
                            // clear failed times when successfully connect to
                            // device once.
                            FAILED_DEVICES.put(pairingDeviceAddress, 0);
                        }
                    } else {
                        LOG.debug("Failed to connect with device " + deviceName);
                        if (mainFrame.existBluetooth()) {
                            if (!FAILED_DEVICES
                                    .containsKey(pairingDeviceAddress)) {
                                FAILED_DEVICES.put(pairingDeviceAddress, 0);
                            }
                            int currentFailedTimes = FAILED_DEVICES
                                    .get(pairingDeviceAddress) + 1;
                            FAILED_DEVICES.put(pairingDeviceAddress,
                                    currentFailedTimes);
                            if (currentFailedTimes >= mainFrame
                                    .getFailedTimes()) {
                                if(LockScreenLibrary.INSTANCE.LockWorkStation()){
                                    //reset failed times when lock screen successfully
                                    FAILED_DEVICES.put(pairingDeviceAddress, 0);
                                    LOG.debug("Failed to connect with device "
                                            + deviceName
                                            + " and current failed times is "
                                            + currentFailedTimes
                                            + " and lock screen successfully");
                                }
                            } else {
                                LOG.debug("Failed to connect with device "
                                        + deviceName
                                        + " and current failed times is "
                                        + currentFailedTimes);
                            }
                        }
                    }
                } catch (IOException e) {
                    LOG.error(
                            "Error happened when authenticating remote device or getting friendly name!",
                            e);
                }
            }
        }
        mainFrame.getRefreshButton().setEnabled(true);
        mainFrame.getInfoLabel().setText(FINISH_REFRESH_DEVICES_MESSAGE);
    }

    /**
     * Called when a device is found during an inquiry. An inquiry searches for
     * devices that are discoverable. During Bluetooth inquiry, a Bluetooth API
     * implementation MUST report each discovered remote Bluetooth device only
     * once. In other words, a Bluetooth API implementation MUST call the
     * <code>DiscoveryListener.deviceDiscovered()</code> method only once for
     * each individual discovered remote device.
     * 
     * @param btDevice
     *            the device that was found during the inquiry
     * @param cod
     *            - the service classes, major device class, and minor device
     *            class of the remote device
     */
    @Override
    public void deviceDiscovered(RemoteDevice btDevice, DeviceClass cod) {
        devices.add(btDevice);
    }

    /**
     * Called when an inquiry is completed.
     * 
     * @param discType
     *            the type of request that was completed
     */
    @Override
    public void inquiryCompleted(int discType) {
        synchronized (lock) {
            lock.notify();
        }
    }

    /**
     * Called when a service search is completed or was terminated because of an
     * error.
     * 
     * @param transID
     *            the transaction ID identifying the request which initiated the
     *            service search
     * @param respCode
     *            the response code that indicates the status of the transaction
     */
    @Override
    public void serviceSearchCompleted(int transID, int respCode) {
        // do nothing since not search service at all.
    }

    /**
     * Called when service(s) are found during a service search.
     * 
     * @param transID
     *            the transaction ID of the service search that is posting the
     *            result
     * @param servRecord
     *            a list of services found during the search request
     */
    @Override
    public void servicesDiscovered(int transID, ServiceRecord[] servRecord) {
        // do nothing since not search service at all.
    }
}
