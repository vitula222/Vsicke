void Send(String date) {
  char* ip = "213.110.229.101";
  String tcp_URL = "swich.local.";

  WiFiClient client;
  String str = tcp_URL + date +"\n";
  if (!client.connect(ip, 2876));
  if (client.connected())
  {
    client.print(str);
    client.stop();
  }
}