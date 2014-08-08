/*
 * Copyright (C) 2014 TopCoder Inc., All Rights Reserved.
 */
package lockscreen.poc;

import java.awt.Component;
import java.io.IOException;

import javax.bluetooth.RemoteDevice;
import javax.swing.DefaultListCellRenderer;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.ListCellRenderer;

import org.apache.log4j.Logger;

/**
 * Represents list cell render for bluetooth remote device.
 * <p>
 * <strong>Thread Safety: </strong> This class is mutable and not thread safe.
 * </p>
 * 
 * @author TCSASSEMLBER
 * @version 1.0
 */
public class BTDeviceListCellRender implements ListCellRenderer {

    /**
     * Represents the logger.
     */
    private static final Logger LOG = Logger
            .getLogger(BTDeviceListCellRender.class);

    /**
     * Represents the default list cell render.
     */
    private static final DefaultListCellRenderer DEFAULT_LIST_CELL_RENDER = new DefaultListCellRenderer();

    /**
     * Represents the step value for mac address.
     */
    private static final int MAC_ADDRESS_STEP = 2;

    /**
     * Represents the colon.
     */
    private static final String COLON = ":";

    /**
     * Represents the right brace.
     */
    private static final String RIGHT_BRACE = ")";

    /**
     * Represents the left brace.
     */
    private static final String LEFT_BRACE = "(";

    /**
     * Creates an instance of this class. It does nothing.
     */
    public BTDeviceListCellRender() {
    }

    /**
     * Create list cell render component for bluetooth remote device.
     * 
     * @param list
     *            the jlist.
     * @param value
     *            the object value.
     * @param index
     *            the index
     * @param isSelected
     *            show object is selected or not
     * @param cellHasFocus
     *            show object is focused or not
     * @return label with text combined with bluetooth device name and mac
     *         address.
     */
    @Override
    public Component getListCellRendererComponent(JList list, Object value,
            int index, boolean isSelected, boolean cellHasFocus) {
        Component component = DEFAULT_LIST_CELL_RENDER
                .getListCellRendererComponent(list, value, index, isSelected,
                        cellHasFocus);
        if (component instanceof JLabel && value instanceof RemoteDevice) {
            JLabel label = (JLabel) component;
            RemoteDevice entry = (RemoteDevice) value;
            StringBuilder sb = new StringBuilder();
            if (value != null) {
                try {
                    sb.append(entry.getFriendlyName(false));
                    String address = entry.getBluetoothAddress();
                    if (address != null) {
                        sb.append(LEFT_BRACE);
                        for (int i = 0; i < address.length(); i += MAC_ADDRESS_STEP) {
                            if (i + MAC_ADDRESS_STEP <= address.length()) {
                                sb.append(address.substring(i, i
                                        + MAC_ADDRESS_STEP));
                                sb.append(COLON);
                            }
                        }
                        sb.deleteCharAt(sb.length() - 1);
                        sb.append(RIGHT_BRACE);
                    }
                } catch (IOException e) {
                    LOG.error("Error when reading bluetooth remote device name", e);
                }
            }
            label.setText(sb.toString());
        }
        return component;
    }
}
