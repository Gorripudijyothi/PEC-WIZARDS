#include <Adafruit_BMP085.h>
#include <ESP8266WiFi.h>
String file1="<!DOCTYPE html>\n"
"\n"
"<html>\n"
"\n"
"<head>\n"
"<title>CONTROL PANEL</title>\n"
"<script type=\"text/javascript\">\n"
"\n"
"window.onload=Pinstatus;\n"
"function Pinstatus(){\n"
"morestatus();\n"
"}\n"
"function morestatus(){\n"
"setTimeout(morestatus, 2000);\n"
"document.getElementById(\"description\").innerHTML = \"Processing Status...............................\";\n"
"server = \"status/99\";\n"
"request = new XMLHttpRequest();\n"
"request.onreadystatechange = updateasyncstatus;\n"
"request.open(\"GET\", server, true);\n"
"request.send(null);\n"
"}\n"
"function updateasyncstatus(){\n"
"if ((request.readyState == 4) && (request.status == 200)){\n"
"result = request.responseText;\n"
"document.getElementById(\"description\").innerHTML = result;\n"
"fullset = result.split(\"#\");\n"
"document.getElementById(\"description\").innerHTML = fullset;\n"
"for(i = 1; i < fullset.length; i++){\n"
"singleset = fullset[i].split(\"=\");\n"
"\n"
"if(singleset[0]=='temperature')\n"
"document.getElementById(\"temperature\").value = singleset[1];\n"
"\n"
"if(singleset[0]=='pressure')\n"
"document.getElementById(\"pressure\").value = singleset[1];\n"
"\n"
"if(singleset[0]=='smoke')\n"
"document.getElementById(\"smoke\").innerHTML = (parseFloat(singleset[1])<350)?'YES':'NO';\n"
"\n"
"if(singleset[0]=='flame')\n"
"document.getElementById(\"flame\").innerHTML = (singleset[1]==1)?'YES':'NO';\n"
"\n"
"if(singleset[0]=='alarm')\n"
"document.getElementById(\"alarm\").innerHTML = (singleset[1]==1)?'ACTIVATED':'INACTIVE';\n"
"\n"
"if(singleset[0]=='sprinkler')\n"
"document.getElementById(\"sprinkler\").innerHTML = (singleset[1]==1)?'YES':'NO';\n"
"\n"
"if(singleset[0]=='fan')\n"
"document.getElementById(\"fan\").innerHTML = (singleset[1]==1)?'ON':'OFF';\n"
"\n"
"if(singleset[0]=='power')\n"
"document.getElementById(\"power\").innerHTML = (singleset[1]==1)?'ON':'OFF';\n"
"}\n"
"}\n"
"}\n"
"function sendbutton(){\n"
"\n"
"document.getElementById(\"description\").innerHTML = \"Processing Button Click\";\n"
"server = \"power/\"\n"
"request = new XMLHttpRequest();\n"
"request.onreadystatechange = updateasyncbutton;\n"
"request.open(\"GET\", server, true);\n"
"request.send(null) ;\n"
"}\n"
"\n"
"function updateasyncbutton(){\n"
"if ((request.readyState == 4) && (request.status == 200))\n"
"{\n"
"result = request.responseText;\n"
"document.getElementById(\"description\").innerHTML = result;\n"
"singleset = result.split(\"=\");\n"
"if(singleset[0]=='power')\n"
"document.getElementById(\"power\").innerHTML = (singleset[1]==1)?'ON':'OFF';\n"
"\n"
"}\n"
"}\n"
"</script>\n"
"</head>\n"
"\n"
"<body bgcolor=\"#BDE7F5\">\n"
"<h1 align=\"center\">CONTROL PANEL</h1>\n"
"\n"
"<table cellpadding=\"12\" style=\"float:left\"  >\n"
"<caption><h2>ROOM 1</h2></caption>\n"
"\n"
"<tr>\n"
"<th align=\"center\" colspan=\"6\" >TEMPERATURE(deg C):</th>\n"
"<th><input type=\"text\" style=\"text-align: center;\" name=\"analog\" id=\"temperature\" value=\"0\" size=\"14\" ></th>\n"
"</tr>\n"
"\n"
"<tr>\n"
"<th align=\"center\" colspan=\"6\" >PRESSURE(Pa):</th>\n"
"<th><input type=\"text\" style=\"text-align: center;\" name=\"analog\" id=\"pressure\" value=\"0\" size=\"14\" ></th>\n"
"</tr>\n"
"\n"
"<tr>\n"
"<th align=\"center\" colspan=\"6\" >SMOKE STATUS:</th>\n"
"<th align=\"center\" id=\"smoke\" >NO</th>\n"
"</tr>\n"
"\n"
"<tr>\n"
"<th align=\"center\" colspan=\"6\" >FLAME STATUS:</th>\n"
"<th align=\"center\" id=\"flame\">YES</th>\n"
"</tr>\t\n"
"\n"
"<tr>\n"
"<th align=\"center\" colspan=\"6\" >ROOM POWER STATUS:</th>\n"
"<th align=\"center\" id=\"power\">OFF</th>\n"
"</tr>\n"
"\n"
"<tr>\n"
"<th align=\"center\" colspan=\"6\" >POWER BUTTON:</th>\n"
"<th><button onclick=\"sendbutton();\" >ON/OFF</button></th>\n"
"</tr>\n"
"\n"
"<tr>\n"
"<th align=\"center\" colspan=\"6\" >ALARM STATUS:</th>\n"
"<th align=\"center\" id=\"alarm\">INACTIVE</th>\n"
"</tr>\n"
"\n"
"<tr>\n"
"<th align=\"center\" colspan=\"6\" >SPRINKLERS STATUS:</th>\n"
"<th align=\"center\" id=\"sprinkler\">ON</th>\n"
"</tr>\n"
"\n"
"<tr>\n"
"<th align=\"center\" colspan=\"6\" >EXHAUST FAN:</th>\n"
"<th align=\"center\" id=\"fan\">ON</th>\n"
"</tr>\n"
"\n"
"</table>\n"
"\n"
"<table cellpadding=\"12\" style=\"float:left\"  >\n"
"<caption><h2>ROOM 2</h2></caption>\n"
"\n"
"<tr>\n"
"<th align=\"center\" colspan=\"6\" >TEMPERATURE(deg C):</th>\n"
"<th><input type=\"text\" style=\"text-align: center;\" name=\"analog\"  value=\"0\" size=\"14\" ></th>\n"
"</tr>\n"
"\n"
"<tr>\n"
"<th align=\"center\" colspan=\"6\" >PRESSURE(mb):</th>\n"
"<th><input type=\"text\" style=\"text-align: center;\" name=\"analog\"  value=\"0\" size=\"14\" ></th>\n"
"</tr>\n"
"\n"
"<tr>\n"
"<th align=\"center\" colspan=\"6\" >SMOKE STATUS:</th>\n"
"<th align=\"center\"  >NO</th>\n"
"</tr>\n"
"\n"
"<tr>\n"
"<th align=\"center\" colspan=\"6\" >FLAME STATUS:</th>\n"
"<th align=\"center\" id=\"flame\">YES</th>\n"
"</tr>\t\n"
"\n"
"<tr>\n"
"<th align=\"center\" colspan=\"6\" >ROOM POWER STATUS:</th>\n"
"<th align=\"center\" >OFF</th>\n"
"</tr>\n"
"\n"
"<tr>\n"
"<th align=\"center\" colspan=\"6\" >POWER BUTTON:</th>\n"
"<th><button onclick=\"sendbutton();\" >ON/OFF</button></th>\n"
"</tr>\n"
"\n"
"<tr>\n"
"<th align=\"center\" colspan=\"6\" >ALARM STATUS:</th>\n"
"<th align=\"center\" >INACTIVE</th>\n"
"</tr>\n"
"\n"
"<tr>\n"
"<th align=\"center\" colspan=\"6\" >SPRINKLERS STATUS:</th>\n"
"<th align=\"center\" >ON</th>\n"
"</tr>\n"
"<tr>\n"
"<th align=\"center\" colspan=\"6\" >EXHAUST FAN:</th>\n"
"<th align=\"center\" >ON</th>\n"
"</tr>\n"
"</table>\n"
"\n"
"\n"
"</body>\n"
"<p  id=\"description\">-</p>\n"
"</html>";

Adafruit_BMP085 bmp;
double T,P;
int smoke=0, flame=0,help=0;
boolean value=0;
String message="";
void lookup(){
  smoke = analogRead(A0);
  flame = !digitalRead(2);
  help = digitalRead(14);
  T=bmp.readTemperature();
  P=bmp.readPressure();
   if(flame){    //if flame
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
  }else if(smoke<350&&(!flame)){ //if only smoke
     digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
      digitalWrite(15,HIGH);
      digitalWrite(16,LOW);
  }else {
     digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    digitalWrite(15,LOW);
   
    
  }
  if(help==HIGH||flame||smoke<350){
    digitalWrite(12,HIGH);
  }
    else{
      digitalWrite(12,LOW);
    }
}
const char* ssid = "Mangatayaru";
const char* password = "12345678";

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);
  bmp.begin();


pinMode(2,INPUT);
pinMode(14,INPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(15,OUTPUT);
pinMode(16,OUTPUT);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    lookup();
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    lookup();
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  lookup();
  // Read the first line of the request
  String command1 = client.readStringUntil('/');
  String command = client.readStringUntil('/');
  Serial.println(command1);
  Serial.println(command);

if (command == "status") {
  client.print(F("status#"));
  message+="smoke=";
      message+=(String)smoke;
      message+="#";
      message+="flame=";
      message+=(String)flame;
      message+="#";
       message+="help=";
       message+=(String)help;
       message+="#";
       message+="alarm=";
       message+=(String)digitalRead(12);
       message+="#";
       message+="sprinkler=";
       message+=(String)digitalRead(13);
       message+="#";
       message+="fan=";
       message+=(String)digitalRead(15);
        message+="#";
       message+="power=";
       message+=(String)digitalRead(16);
       message+="#";
       message+="temperature=";
       message+=(String)T;
       message+="#";
       message+="pressure=";
       message+=(String)P;
       client.print(message);
       message="";
}else if(command=="power"){
  value= digitalRead(16);
  digitalWrite(16,!value);
  client.print(F("status#"));
  client.print(F("power="));
  client.print(!value);
  
}

else {  // Prepare the response
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
  s += file1;  
  client.flush();
  // Send the response to the client
while(s.length()>2000)
{
  String dummy = s.substring(0,2000);
  client.print(dummy);
  s.replace(dummy," ");
}
  
  client.print(s);
  delay(1);
  Serial.println("Client disconnected");

  // The client will actually be disconnected 
  // when the function returns and 'client' object is destroyed
}
}
