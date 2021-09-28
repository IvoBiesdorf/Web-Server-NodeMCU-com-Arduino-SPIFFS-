
void pgIndex() {   
  File html = SPIFFS.open("/index.html","r");
  server.send(200, "text/html", html.readString());
  html.close(); 
}
void style_css() { 
  File style_css = SPIFFS.open("/style.css","r");
  server.send(200, "text/css", style_css.readString());
  style_css.close(); 
}
void statuis(){
  status_input1 = digitalRead(4)? " Ligado ":" Desligado ";
  status_input2 = digitalRead(5)? " Ligado ":" Desligado ";
  String dadosXml = "";
  dadosXml = "<?xml version = \"1.0\"?>";
  dadosXml +="<status>"; 
  dadosXml += "<dados>";
  dadosXml += btnLiga;
  dadosXml += "</dados>";
  dadosXml += "<dados>";
  dadosXml += btnDesliga;
  dadosXml += "</dados>";
  dadosXml += "<dados>";
  dadosXml += status_input1;
  dadosXml += "</dados>";
  dadosXml += "<dados>";
  dadosXml += status_input2;
  dadosXml += "</dados>";
  dadosXml += "</status>";
  server.send(200, "text/xml", dadosXml); 
}

void liga_desliga(){
  String btn = server.arg("btn");
  if(btn == "ligar"){
    btnLiga = "Ligado";
    btnDesliga = "Desligar";
    digitalWrite(16, HIGH); 
  }else 
  if(btn == "desligar"){
    btnDesliga = "Desligado";
    btnLiga = "Ligar";
    digitalWrite(16, LOW);
  }
  String dadosXml = "";
  dadosXml = "<?xml version = \"1.0\"?>";
  dadosXml +="<status>"; 
  dadosXml += "<dados>";
  dadosXml += btnLiga;
  dadosXml += "</dados>";
  dadosXml += "<dados>";
  dadosXml += btnDesliga;
  dadosXml += "</dados>";
  dadosXml += "</status>";
  server.send(200, "text/xml", dadosXml);
}
