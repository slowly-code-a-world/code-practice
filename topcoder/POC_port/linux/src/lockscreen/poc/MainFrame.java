/*
 * Copyright (C) 2014 TopCoder Inc., All Rights Reserved.
 */
package lockscreen.poc;

import javax.bluetooth.DiscoveryAgent;
import javax.bluetooth.LocalDevice;
import javax.bluetooth.RemoteDevice;

import org.apache.log4j.Logger;

import com.intel.bluetooth.RemoteDeviceHelper;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashSet;
import java.util.Properties;
import java.util.Set;
import java.util.Vector;

import javax.swing.DefaultListModel;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JButton;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JCheckBox;
import javax.swing.JScrollPane;
import javax.swing.Timer;
import javax.swing.UIManager;
import javax.swing.ListSelectionModel;

/**
 * Represents main frame to render lock screen application,it has following
 * functions.
 * <ul>
 * <li>Display all the discoverable bluetooth mobile phones in a list</li>
 * <li>User is able to pair and select specific mobile phones as the target</li>
 * <li>After the target is specified, the app will lock the Windows screen when
 * the target's bluetooth signal is lost</li>
 * </ul>
 * <p>
 * <strong>Thread Safety: </strong> This class is not thread safe since base
 * class is not thread safe.
 * </p>
 * 
 * @author TCSASSEMLBER
 * @version 1.0
 */
public class MainFrame extends JFrame {
    /**
     * Represents the window look and feel string for swing.
     */
    private static final String SWING_WINDOWS_LOOK_AND_FEEL = "com.sun.java.swing.plaf.windows.WindowsLookAndFeel";

    /**
     * Represents the title of error message dialog.
     */
    private static final String ERROR = "Error";

    /**
     * Represents the title of warning message dialog.
     */
    private static final String WARN = "Warn";

    /**
     * Represents the application properties file name.
     */
    private static final String APP_PROPERTIES_NAME = "app.properties";

    /**
     * Represents the start to pair message.
     */
    private static final String START_TO_PAIR_MESSAGE = "Start to pair to device with name ";

    /**
     * Represents the must select one device message.
     */
    private static final String SELECT_ONE_DEVICE_MESSAGE = "Please select one bluetooth device first!";

    /**
     * Represents the wait for previous refresh message.
     */
    private static final String WAIT_FOR_PREVIOUS_MESSAGE = "Please wait for previous getting devices job!";

    /**
     * Represents the pairing unsuccessful with device message.
     */
    private static final String PAIRING_UNSUCCESSFUL_WITH_DEVICE_MESSAGE = "Pairing unsuccessful with device ";

    /**
     * Represents the pairing successful with device message.
     */
    private static final String PAIRINGL_SUCCESSFUL_WITH_DEVICE_MESSAGE = "Pairing successful with device ";

    /**
     * Represents the pair button label.
     */
    private static final String PAIR_LABEL = "Pair";

    /**
     * Represents the begin to refresh bluetooth message.
     */
    private static final String BEGIN_TO_REFRESH_BLUETOOTH_DEVICES_MESSAGE = "Begin to refresh bluetooth devices.";
    /**
     * Represents the bluetooth device not available message.
     */
    private static final String BT_LOCKING_NO_AVAILABLE_MESSAGE = "BT locking is no longer available!";

    /**
     * Represents the refresh button label.
     */
    private static final String REFRESH_LABEL = "Refresh";

    /**
     * Represents the empty text.
     */
    private static final String EMPTY_TEXT = " ";

    /**
     * Represents the pair device label.
     */
    private static final String PAIRED_DEVICES_LABEL = "Paired Devices";
    /**
     * Represents the preferred height.
     */
    private static final int PREFERRED_HEIGHT = 320;

    /**
     * Represents the preferred width.
     */
    private static final int PREFERRED_WIDTH = 480;

    /**
     * Represents the application title.
     */
    private static final String TITLE = "Lock Screen";

    /**
     * Represents the logger.
     */
    private static final Logger LOG = Logger.getLogger(MainFrame.class);

    /**
     * Represents the serial version uid.
     */
    private static final long serialVersionUID = 7927217092996461499L;

    /**
     * Represents the error message when it cannot found bluetooth device or
     * bluetooth device is turned off when launching application.
     */
    private static final String ERROR_INITIAL_BLUETOOTH_MESSAGE = 
            "Please enable bluetooth device or make sure exist bluetooth device!";

    /**
     * Represents the default check devices interval,the unit is milliseconds.
     */
    private static final int DEFAULT_CHEK_DEVICES_INTERVAL = 30 * 1000;

    /**
     * Represents the default pin code.
     */
    private static final String DEFAULT_PIN = "111111";

    /**
     * Represents the default failed times when locking screen.
     */
    private static final int DEFAULT_FAILED_TIMES = 2;

    /**
     * Represents the property key for pin code.
     */
    private static final String KEY_PIN = "pin";

    /**
     * Represents the property key for checking devices interval.
     */
    private static final String KEY_CHECK_DEVICES_INTERVAL = "checkDevicesInternal";

    /**
     * Represents the property key for failed times.
     */
    private static final String KEY_FAILED_TIMES = "failedTimes";

    /**
     * Represents the devices list.
     */
    private JList devicesList;

    /**
     * Represents the local device name.
     */
    private String localDeviceName;

    /**
     * Represents the info Label.
     */
    private JLabel infoLabel;

    /**
     * Represents the device comboBox Label.
     */
    private JLabel deviceComboBoxLabel;

    /**
     * Represents the default list model.
     */
    private DefaultListModel model;

    /**
     * Represents the refresh button.
     */
    private JButton refreshButton;

    /**
     * Represents the pair button.
     */
    private JButton pairButton;

    /**
     * Represents the lock checkBox.
     */
    private JCheckBox lockCheckBox;

    /**
     * Represents the device comboBox.
     */
    private JComboBox deviceComboBox;

    /**
     * Represents the check devices timer.
     */
    private Timer checkDevicesTimer;

    /**
     * Represents the paired devices addresses.
     */
    private Set<String> pairedDeviceAddresses;

    /**
     * Represents the paired devices.
     */
    private Vector<RemoteDevice> pairedDevices;

    /**
     * Represents the code.
     */
    private String pin;

    /**
     * Represents the check devices interval.
     */
    private int checkDevicesInterval;

    /**
     * Represents the failed times.
     */
    private int failedTimes;

    /**
     * Creates an instance of this class.
     */
    public MainFrame() {
        super(TITLE);
        super.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        super.addWindowListener(new WindowAdapter() {
            /**
             * Handle window close event
             * 
             * @param e
             *            the window event.
             */
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                int result = JOptionPane.showConfirmDialog(null,
                        "Are you sure to exit application?", "Exit",
                        JOptionPane.YES_NO_OPTION, JOptionPane.WARNING_MESSAGE);
                if (result == JOptionPane.YES_OPTION) {
                    checkDevicesTimer.stop();
                    System.exit(0);
                }
            }
        });
        super.setPreferredSize(new Dimension(PREFERRED_WIDTH, PREFERRED_HEIGHT));
        loadProperties();
        getContentPane().setLayout(new BorderLayout());
        JPanel infoPanel = new JPanel();
        infoPanel.setLayout(new BorderLayout());
        JPanel deviceComboBoxPanel = new JPanel();
        deviceComboBoxLabel = new JLabel();
        deviceComboBoxLabel.setText(PAIRED_DEVICES_LABEL);
        deviceComboBoxPanel.add(deviceComboBoxLabel);
        infoPanel.add(deviceComboBoxPanel, BorderLayout.NORTH);
        pairedDevices = new Vector<RemoteDevice>();
        pairedDeviceAddresses = new HashSet<String>();
        deviceComboBox = new JComboBox(pairedDevices);
        BTDeviceListCellRender btDeviceListCellRender = new BTDeviceListCellRender();
        deviceComboBox.setRenderer(btDeviceListCellRender);
        infoPanel.add(deviceComboBox, BorderLayout.CENTER);
        JPanel infoLabelPanel = new JPanel();
        infoLabel = new JLabel();
        infoLabel.setText(EMPTY_TEXT);
        infoLabelPanel.add(infoLabel);
        infoPanel.add(infoLabelPanel, BorderLayout.SOUTH);
        getContentPane().add(infoPanel, BorderLayout.NORTH);
        model = new DefaultListModel();
        devicesList = new JList(model);
        devicesList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        devicesList.setCellRenderer(btDeviceListCellRender);
        JScrollPane listPane = new JScrollPane(devicesList);
        getContentPane().add(listPane, BorderLayout.CENTER);
        JPanel panel = new JPanel();
        getContentPane().add(panel, BorderLayout.SOUTH);
        lockCheckBox = new JCheckBox(TITLE);
        lockCheckBox.setSelected(true);
        panel.add(lockCheckBox);
        refreshButton = new JButton(REFRESH_LABEL);
        panel.add(refreshButton);
        final MainFrame mainFrame = this;
        refreshButton.addActionListener(new ActionListener() {
            /**
             * Perform refresh devices action.
             * 
             * @event the action event.
             */
            public void actionPerformed(ActionEvent event) {
                refreshButton.setEnabled(false);
                if (existBluetooth()) {
                    enableFrame();
                    logInfoMessage(BEGIN_TO_REFRESH_BLUETOOTH_DEVICES_MESSAGE);
                    try {
                        BTDeviceDiscoveryTask process = new BTDeviceDiscoveryTask(
                                mainFrame);
                        process.execute();
                    } catch (Exception e) {
                        LOG.error("Error when getting bluetooth devices!", e);
                    }
                }
            }
        });
        pairButton = new JButton(PAIR_LABEL);
        panel.add(pairButton);
        pairButton.addActionListener(new ActionListener() {
            /**
             * Perform pair devices action.
             * 
             * @event the action event.
             */
            public void actionPerformed(ActionEvent event) {
                if (!refreshButton.isEnabled() && model.size() == 0) {
                    showWarnMessage(WAIT_FOR_PREVIOUS_MESSAGE);
                    return;
                }
                int selected[] = devicesList.getSelectedIndices();
                if (selected.length != 1) {
                    showWarnMessage(SELECT_ONE_DEVICE_MESSAGE);
                } else {
                    int index = selected[0];
                    RemoteDevice remoteDevice = (RemoteDevice) devicesList
                            .getModel().getElementAt(index);
                    try {
                        logInfoMessage(START_TO_PAIR_MESSAGE
                                + remoteDevice.getFriendlyName(false));
                        pairButton.setEnabled(false);
                        boolean paired = RemoteDeviceHelper.authenticate(
                                remoteDevice, pin);
                        StringBuilder sb = new StringBuilder();
                        if (paired) {
                            sb.append(PAIRINGL_SUCCESSFUL_WITH_DEVICE_MESSAGE);
                            String pairedDeviceAddress = remoteDevice
                                    .getBluetoothAddress();
                            if (!pairedDeviceAddresses
                                    .contains(pairedDeviceAddress)) {
                                pairedDeviceAddresses.add(pairedDeviceAddress);
                                pairedDevices.add(remoteDevice);
                                deviceComboBox.setSelectedItem(remoteDevice);
                            }
                        } else {
                            sb.append(PAIRING_UNSUCCESSFUL_WITH_DEVICE_MESSAGE);
                        }
                        sb.append(remoteDevice.getFriendlyName(false));
                        logInfoMessage(sb.toString());
                    } catch (IOException e) {
                        LOG.error(
                                "Error when getting device name or authenticating!",
                                e);
                    } finally {
                        pairButton.setEnabled(true);
                    }
                }
            }
        });

        ActionListener checkDeviceStatus = new ActionListener() {
            /**
             * Perform check bluetooth device action.
             * 
             * @e the action event.
             */
            @Override
            public void actionPerformed(ActionEvent e) {
                if (refreshButton.isEnabled()) {
                    refreshButton.doClick();
                }
            }
        };
        checkDevicesTimer = new Timer(checkDevicesInterval, checkDeviceStatus);

    }

    /**
     * Start check devices timer.
     */
    public void startCheckDeviceTimer() {
        checkDevicesTimer.start();
        this.refreshButton.doClick();
    }

    /**
     * Log information message.
     * 
     * @param message
     *            the message.
     */
    private void logInfoMessage(String message) {
        LOG.info(message);
        infoLabel.setText(message);
    }

    /**
     * Load pin and check devices interval from properties file.
     */
    private void loadProperties() {
        InputStream input = null;
        Properties props = new Properties();
        try {
            input = new FileInputStream(APP_PROPERTIES_NAME);
            props.load(input);
            pin = props.getProperty(KEY_PIN);
            checkDevicesInterval = Integer.parseInt(props
                    .getProperty(KEY_CHECK_DEVICES_INTERVAL));
            failedTimes = Integer.parseInt(props.getProperty(KEY_FAILED_TIMES));
        } catch (IOException e) {
            LOG.error("Error happened when reading properties file", e);
        } catch (NumberFormatException e) {
            LOG.error(
                    "invalid check devices interval value exists in properties file",
                    e);
        } finally {
            if (input != null) {
                try {
                    input.close();
                } catch (IOException e) {
                    LOG.error("Error happened when closing properties file", e);
                }
            }
        }
        if (isNullOrEmpty(pin)) {
            pin = DEFAULT_PIN;
            LOG.error("can not find valid pin from properties file!");
        }
        if (checkDevicesInterval <= 0) {
            checkDevicesInterval = DEFAULT_CHEK_DEVICES_INTERVAL;
            LOG.error("can not find valid check devices interval from properties file!");
        }
        if (failedTimes <= 0) {
            failedTimes = DEFAULT_FAILED_TIMES;
            LOG.error("can not find valid failed times from properties file!");
        }
        LOG.debug("pin=" + pin);
        LOG.debug("checkDevicesInterval=" + checkDevicesInterval);
        LOG.debug("failedTimes=" + failedTimes);
    }

    /**
     * Disable frame when bluetooth is not available
     */
    private void disableFrame() {
        if (pairButton != null) {
            pairButton.setEnabled(false);
        }
        if (model != null) {
            model.clear();
        }
        if (lockCheckBox != null) {
            lockCheckBox.setEnabled(false);
        }
        if (deviceComboBox != null) {
            deviceComboBox.setEnabled(false);
        }
        if (infoLabel != null) {
            infoLabel.setEnabled(false);
        }
        if (deviceComboBoxLabel != null) {
            deviceComboBoxLabel.setEnabled(false);
        }
    }

    /**
     * Enable frame when bluetooth is available
     */
    private void enableFrame() {
        if (pairButton != null) {
            pairButton.setEnabled(true);
        }
        if (lockCheckBox != null) {
            lockCheckBox.setEnabled(true);
        }
        if (deviceComboBox != null) {
            deviceComboBox.setEnabled(true);
        }
        if (infoLabel != null) {
            infoLabel.setEnabled(true);
        }
        if (deviceComboBoxLabel != null) {
            deviceComboBoxLabel.setEnabled(true);
        }
    }

    /**
     * Show warning message.
     * 
     * @param message
     *            the message.
     */
    private static void showWarnMessage(String message) {
        JOptionPane.showMessageDialog(null, message, WARN,
                JOptionPane.WARNING_MESSAGE);
    }

    /**
     * Show error message.
     * 
     * @param message
     *            the message.
     */
    private static void showErrorMessage(String message) {
        JOptionPane.showMessageDialog(null, message, ERROR,
                JOptionPane.ERROR_MESSAGE);
    }

    /**
     * Check string is null or empty
     * 
     * @param str
     *            the input string
     * @return true if string is null or empty
     */
    private static boolean isNullOrEmpty(String str) {
        return str == null || str.trim().isEmpty();
    }

    /**
     * Check bluetooth device is available
     * 
     * @return true if bluetooth is available
     */
    public boolean existBluetooth() {
        // when use usb bluetooth device will use below check.
        boolean btReady = true;
        if (!LocalDevice.isPowerOn()) {
            btReady = false;
        }
        if (btReady) {
            try {
                LocalDevice localDevice = LocalDevice.getLocalDevice();
                if (localDeviceName != null
                        && !localDeviceName.equals(localDevice
                                .getFriendlyName())) {
                    btReady = false;
                } else {
                    localDeviceName = localDevice.getFriendlyName();
                }
            } catch (Exception e) {
                btReady = false;
                LOG.error("Error when getting local bluetooth device", e);
            }
        }
        if (!btReady) {
            if (!this.isVisible()) {
                showErrorMessage(ERROR_INITIAL_BLUETOOTH_MESSAGE);
                System.exit(-1);
            } else {
                LOG.debug(BT_LOCKING_NO_AVAILABLE_MESSAGE);
                disableFrame();
                showErrorMessage(BT_LOCKING_NO_AVAILABLE_MESSAGE);
                refreshButton.setEnabled(true);
            }
        }
        return btReady;
    }

    /**
     * Load old devices when launching application first time.
     */
    public void loadOldDevices() {
        try {
            LocalDevice localDevice = LocalDevice.getLocalDevice();
            DiscoveryAgent discAgent = localDevice.getDiscoveryAgent();
            RemoteDevice[] oldDevices = discAgent
                    .retrieveDevices(DiscoveryAgent.PREKNOWN);
            if (oldDevices != null) {
                for (RemoteDevice device : oldDevices) {
                    pairedDeviceAddresses.add(device.getBluetoothAddress());
                    pairedDevices.add(device);
                    if (deviceComboBox.getSelectedItem() == null) {
                        deviceComboBox.setSelectedItem(device);
                    }
                }
            }
        } catch (Exception e) {
            LOG.error("Error when getting old bluetooth devices", e);
        }
    }

    /**
     * Getter for the <code>infoLabel</code> field
     * 
     * @return the info label
     */
    public JLabel getInfoLabel() {
        return infoLabel;
    }

    /**
     * Getter for the <code>model</code> field
     * 
     * @return the model
     */
    public DefaultListModel getModel() {
        return model;
    }

    /**
     * Getter for the <code>refreshButton</code> field
     * 
     * @return the refreshButton
     */
    public JButton getRefreshButton() {
        return refreshButton;
    }

    /**
     * Getter for the <code>lockCheckBox</code> field
     * 
     * @return the lock check box
     */
    public JCheckBox getLockCheckBox() {
        return lockCheckBox;
    }

    /**
     * Getter for the <code>deviceComboBox</code> field
     * 
     * @return the deviceComboBox
     */
    public JComboBox getDeviceComboBox() {
        return deviceComboBox;
    }

    /**
     * Getter for the <code>pin</code> field
     * 
     * @return the pin code
     */
    public String getPin() {
        return pin;
    }

    /**
     * Getter for the <code>failedTimes</code> field
     * 
     * @return the failed times
     */
    public int getFailedTimes() {
        return failedTimes;
    }

    /**
     * Render main frame
     * 
     * @param args
     *            the input arguments,actually it does not accept any input
     *            arguments.
     */
    public static void main(String[] args) {
        try {
	 	
            //UIManager.setLookAndFeel(SWING_WINDOWS_LOOK_AND_FEEL);
	    System.loadLibrary("bluecove");	
	    UIManager.setLookAndFeel(UIManager.getCrossPlatformLookAndFeelClassName());	
            final MainFrame frame = new MainFrame();
            if (frame.existBluetooth()) {
                EventQueue.invokeLater(new Runnable() {
                    @Override
                    public void run() {
                        frame.pack();
                        frame.setLocationRelativeTo(null);
                        frame.setVisible(true);
                        frame.loadOldDevices();
                        frame.startCheckDeviceTimer();
                    }
                });
            }
	    	
        } catch (Exception e) {
            LOG.error("Error when rendering main frame", e);
        }
    }
}
