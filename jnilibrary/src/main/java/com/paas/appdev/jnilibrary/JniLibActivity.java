package com.paas.appdev.jnilibrary;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

import com.paas.appdev.jnilibrary.controller.AESDESEncrpyController;
import com.paas.appdev.jnilibrary.controller.BaseController;
import com.paas.appdev.jnilibrary.controller.Jni2JavaStaticController;
import com.paas.appdev.jnilibrary.controller.JniReflectController;
import com.paas.appdev.jnilibrary.controller.LogController;
import com.paas.appdev.jnilibrary.controller.MethodParamsController;
import com.paas.appdev.jnilibrary.controller.NonStaticMethodController;
import com.paas.appdev.jnilibrary.controller.RetuurnAndParamsController;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class JniLibActivity extends AppCompatActivity {
    static {
        System.loadLibrary("jnilib");
    }

    private RecyclerView recycle;
    private List<BaseController> datas = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_jni_lib);
        initData();
        recycle = findViewById(R.id.recycle);
        recycle.setLayoutManager(new LinearLayoutManager(this, LinearLayoutManager.VERTICAL, false));
        RecyclerView.Adapter adapter = new OperAdapter(this, datas);
        recycle.setAdapter(adapter);
    }

    private void initData() {
        datas.add(new MethodParamsController("jni方法参数"));
        datas.add(new LogController("c语言调用java打印日志功能，会在控制台打印日志"));
        datas.add(new RetuurnAndParamsController("java方法的四中返回参数类型和形参类型，可以看到几种函数的生命，调用无效"));
        datas.add(new Jni2JavaStaticController("jni调用java static方法，会在控制台打印日志"));
        datas.add(new NonStaticMethodController("jni非静态方法调用，会在控制台打印日志"));
        datas.add(new JniReflectController("jni非静态方法调用，会在控制台打印日志"));
        datas.add(new AESDESEncrpyController("AES加密"));
    }

    public static class OperAdapter extends RecyclerView.Adapter<OperHolder> {
        private final Context context;
        private List<BaseController> datas;

        public OperAdapter(Context context, List<BaseController> datas) {
            this.context = context;
            this.datas = datas;
        }

        @NonNull
        @Override
        public OperHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
            View inflate = View.inflate(context, R.layout.item, null);
            return new OperHolder(inflate);
        }

        @Override
        public void onBindViewHolder(@NonNull OperHolder holder, int position) {
            BaseController operData = datas.get(position);
            operData.deal(holder);
        }

        @Override
        public int getItemCount() {
            return datas.size();
        }
    }

    public static class OperHolder extends RecyclerView.ViewHolder {
        public Button btn;
        public TextView tv;

        public OperHolder(@NonNull View itemView) {
            super(itemView);
            tv = itemView.findViewById(R.id.item_tv);
            btn = itemView.findViewById(R.id.item_btn);
        }
    }
}
