package com.ssovit.example

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        findViewById<TextView>(R.id.sample_text).text = socialRoulette("/video/6956360214941535493")
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    private external fun socialRoulette(urlPath: String): String

    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("cms")
        }
    }
}