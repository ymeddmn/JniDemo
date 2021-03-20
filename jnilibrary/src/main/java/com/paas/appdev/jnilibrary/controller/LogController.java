package com.paas.appdev.jnilibrary.controller;

/**
 * author  :mayong
 * function:
 * date    :2020-08-18
 **/
public class LogController extends BaseController {
    public LogController(String desc) {
        super(desc);
    }

    @Override
    public void click() {
        logE();
    }

    @Override
    public void operate() {

    }

    /**
     * 打印日志
     */
    public native void logE();
}
