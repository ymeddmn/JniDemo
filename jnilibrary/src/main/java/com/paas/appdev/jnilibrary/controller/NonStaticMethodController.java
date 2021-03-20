package com.paas.appdev.jnilibrary.controller;

import android.util.Log;

/**
 * author  :mayong
 * function:
 * date    :2020-08-19
 **/
public class NonStaticMethodController extends BaseController {
    public NonStaticMethodController(String desc) {
        super(desc);
    }

    @Override
    public void click() {
        callnonstaticmethod();
    }

    @Override
    public void operate() {
    }

    /**
     * jni调用java对象的非静态方法
     */
    public native void callnonstaticmethod();


    public void print(){
        Log.e("tag","jni调用java对象的非静态方法");
    }
}
