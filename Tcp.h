void Send(String date) {
  char* ip = "";
  String tcp_URL = "swich.local.";

  WiFiClient client;
  String str = tcp_URL + date +"\n";
  if (!client.connect(ip, 8888));
  if (client.connected())
  {
    client.print(str);
    client.stop();
  }
}
