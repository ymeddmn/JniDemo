package com.paas.appdev.jnilibrary.controller;

import android.view.View;

import com.paas.appdev.jnilibrary.JniLibActivity;
import com.paas.appdev.jnilibrary.listener.OperateListener;

/**
 * author  :mayong
 * function:
 * date    :2020-08-18
 **/
public abstract class BaseController {
    public String desc;
    public OperateListener operListener;
    public JniLibActivity.OperHolder holder;

    public BaseController(String desc) {
        this.desc = desc;
    }

    public void deal(JniLibActivity.OperHolder holder){
        this.holder = holder;
        holder.btn.setText(desc);
        holder.btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                click();
            }
        });
        operate();
    }

    public abstract void click() ;

    public abstract void operate();
    public void setOperListener(OperateListener listener){
        this.operListener = listener;
    }
}
