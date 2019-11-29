package com.encryption.aes;
import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Spinner;

public class MainActivity extends Activity {
    private Spinner spMethod;
    private EditText etPlainText;
    private EditText etCiphertext;

    private final String SECRET_KEY = "asdfghjklqwertyu";
    private final String IV = "1234567899876543";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        spMethod = findViewById(R.id.sn_method);
        etPlainText = findViewById(R.id.et_plaintext);
        etCiphertext = findViewById(R.id.et_ciphertext);
    }

    public void encryption(View view){
        String method = spMethod.getSelectedItem().toString();
        String data = etPlainText.getText().toString();
        etPlainText.setText(null);
        String encryptionData = EncryptionUtils.encryptByAES(data, SECRET_KEY, IV, method);
        etCiphertext.setText(encryptionData);
    }

    public void decrypt(View view){
        String method = spMethod.getSelectedItem().toString();
        String encryptionData = etCiphertext.getText().toString();
        etCiphertext.setText(null);
        String data = EncryptionUtils.decryptByAES(encryptionData, SECRET_KEY, IV, method);
        etPlainText.setText(data);
    }
}
