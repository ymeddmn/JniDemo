package com.paas.appdev.jnilibrary.controller;

import android.util.Log;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

/**
 * author  :mayong
 * function:jni调用java反射
 * date    :2020-08-19
 **/
public class JniReflectController extends BaseController {
    public JniReflectController(String desc) {
        super(desc);
    }

    @Override
    public void click() {
//        callReflect();

//        reflect();
        callReflect();
    }

    @Override
    public void operate() {

    }

    public native void callReflect();

    public void print(){
        Log.e("tag","调用反射方法");
    }

    public void reflect(){
        try {
            Class<JniReflectController> clz = JniReflectController.class;
            Constructor<JniReflectController> constructor = clz.getDeclaredConstructor(String.class);
            JniReflectController instance = constructor.newInstance("哈哈哈");
            Method method = clz.getDeclaredMethod("print");
            method.invoke(instance);
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InstantiationException e) {
            e.printStackTrace();
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        }
    }
    private void print1(){
        Log.e("tag","jni调用私有方法");
    }
}
