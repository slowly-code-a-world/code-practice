/*
 * Copyright (C) 2014 TopCoder Inc., All Rights Reserved.
 */
package lockscreen.poc;

import com.sun.jna.Library;

import com.sun.jna.Native;

import com.sun.jna.Platform;

/**
 * Represents Lock Screen library,it will use JNA to load native lock screen
 * function.
 * <p>
 * <strong>Thread Safety: </strong> This class is immutable and thread safe.
 * </p>
 * 
 * @author TCSASSEMLBER
 * @version 1.0
 */
public interface LockScreenLibrary extends Library {

    /**
     * Represents the lock screen library instance.
     */
    LockScreenLibrary INSTANCE = (LockScreenLibrary)

    /**
     * Load native user32 library.
     */
    Native.loadLibrary((Platform.isWindows()? "user32" : "X11"), LockScreenLibrary.class);

    /**
     * Native lock screen function.
     * 
     * @return return true if lock screen screen successfully.
     */
    boolean LockWorkStation();
}
