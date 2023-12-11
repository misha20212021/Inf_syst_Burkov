#include <ESP8266WiFi.h>
#define WIFI_SSID "HUAWEI-WDM9FH_HiLink"
#define WIFI_PASS "qwerty1234"
#define BOT_TOKEN "6594448595:AAGczESMiHedDyvNYKIsxAIoB3Cfv6NZeJk"
#include <FastBot.h>
FastBot bot(BOT_TOKEN);
void setup() {
  connectWiFi();
  bot.attach(newMsg);

}

void newMsg(FB_msg& msg) {


  // ответить
  bot.replyMessage("Бот в запое, всего доброго.", msg.messageID, msg.chatID);
}

void loop() {
  bot.tick();
}

void connectWiFi() {
  delay(2000);
  Serial.begin(115200);
  Serial.println();
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (millis() > 15000) ESP.restart();
  }
  Serial.println("Connected");
}
