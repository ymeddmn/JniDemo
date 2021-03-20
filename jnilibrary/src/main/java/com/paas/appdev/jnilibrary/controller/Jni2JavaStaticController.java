package com.paas.appdev.jnilibrary.controller;

import android.util.Log;

import java.util.Date;

/**
 * author  :mayong
 * function:
 * date    :2020-08-19
 **/
public class Jni2JavaStaticController extends BaseController {
    public Jni2JavaStaticController(String desc) {
        super(desc);
    }

    @Override
    public void click() {
        callNoParamsAndnoReturn();
        callHasParamsAndnoReturn();
        callNoParamsAndHasReturn();
        callHasParamsAndHasReturn();
        callOtherClassStaticMethod();
    }

    @Override
    public void operate() {

    }

    /**
     * 无参数，无返回值
     */
    public native void callNoParamsAndnoReturn();

    /**
     * 有参数无返回值
     */
    public native void callHasParamsAndnoReturn();

    /**
     * 没有参数，有返回值
     */
    public native void callNoParamsAndHasReturn();

    /**
     * 有参数有返回值
     */
    public native void callHasParamsAndHasReturn();


    /**
     * 调用其它类的方法或者参数
     */
    public native void callOtherClassStaticMethod();
    /**
     * 无参数，无返回值
     */
    public static  void noparamsAndnoreturn(){
        Log.e("tag","jni调用java无参数，无返回值方法");
    }

    /**
     * 有参数,无返回值
     */
    public static void hasparamsAndnoreturn(int m){
        Log.e("tag","jni调用java无参数，无返回值方法"+m);
    }
    /**
     * 没有参数，有返回值
     */
    public static String noparamsAndhasreturn(){
        Log.e("tag","没有参数，有返回值,方法被调用：noparamsAndhasreturn");
        return "哈哈哈";
    }

    /**
     * 有参数有返回值
     * @return
     */
    public static String hasparamsAndhasreturn(String m){
        Log.e("tag","有参数有返回值,方法被调用：noparamsAndhasreturn");
        return "有参数有返回值";
    }
}
