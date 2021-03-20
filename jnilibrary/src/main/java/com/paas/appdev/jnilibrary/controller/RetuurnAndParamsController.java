package com.paas.appdev.jnilibrary.controller;

/**
 * author  :mayong
 * function:java中本地的native方法的四中情况
 * 3.1.无返回值，无参数
 * 太简单，不写了
 * 3.2.有返回值，无参数
 * 3.3.无返回值，有参数
 * 3.4.有返回值，有参数
 * date    :2020-08-18
 **/
public class RetuurnAndParamsController extends BaseController{


    public RetuurnAndParamsController(String desc) {
        super(desc);
    }

    @Override
    public void operate() {
    }

    @Override
    public void click() {
        noparamsAndnoreturn();//c代码打印参数
        boolean b = noparamsAndhasreturn();
        hasparamsAndnoreturn(12);
    }

    /**
     * 无返回值，无参数
     */
    public native void noparamsAndnoreturn();

    /**
     * 有返回值，无参数
     * @return
     */
    public native boolean noparamsAndhasreturn();

    /**
     * 无返回值，有参数
     * @return
     */
    public native void hasparamsAndnoreturn(int a);

    /**
     * 有返回值，有参数
     * @return
     */
    public native String hasparamsAndhasreturn();
}
