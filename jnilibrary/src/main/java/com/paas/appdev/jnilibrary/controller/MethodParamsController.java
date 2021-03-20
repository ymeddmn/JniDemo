package com.paas.appdev.jnilibrary.controller;

import android.view.View;

/**
 * author  :mayong
 * function:
 * date    :2020-08-18
 **/
public class MethodParamsController extends BaseController {

    public MethodParamsController(String desc) {
        super(desc);
    }

    @Override
    public void operate() {
        System.out.println("operate");
    }

    @Override
    public void click() {
        System.out.println("click");
        String content = "";
        short m=2;
        String params = params(1, 2, true, 1, 3, m, "java传入c参数，再被c返回", MethodParamsController.this);
        content+=params;
        content+="--"+getParamsInt(11);
        content+="---"+getParamsString();
        holder.tv.setText(content);
    }

    public native String params(int a, float b, boolean c, double d, long e, short f, String g, MethodParamsController h);
    public native int getParamsInt(int a);
    public native String getParamsString();
}
