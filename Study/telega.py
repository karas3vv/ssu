import telebot
import webbrowser
from currency_converter import CurrencyConverter
from telebot import types

bot = telebot.TeleBot('6327171521:AAFx71fqEiF0xg7U0c4qM6tbE7XuX6YBs8s')

@bot.message_handler(commands=['site', 'website'])
def site(message):
    webbrowser.open('https://vk.com/karas3vv')

currency = CurrencyConverter()
amount = 0

@bot.message_handler(commands=['start'])
def start(message):
    bot.send_message(message.chat.id, 'Введите сумму')
    bot.register_next_step_handler(message, summa)

def summa(message):
    global amount
    try:
        amount = int(message.text.strip())
    except ValueError:
        bot.send_message(message.chat.id, 'Требуется ввести число, а не что-то иное. Введите сумму')
        bot.register_next_step_handler(message, summa)
        return

    if amount > 0:
        markup = types.InlineKeyboardMarkup(row_width=2)
        button1 = types.InlineKeyboardButton('USD/EUR', callback_data='usd/eur')
        button2 = types.InlineKeyboardButton('EUR/USD', callback_data='eur/usd')
        button3 = types.InlineKeyboardButton('USD/GBP', callback_data='usd/gbp')
        button4 = types.InlineKeyboardButton('Другое значение', callback_data='else')
        markup.add(button1, button2, button3, button4)
        bot.send_message(message.chat.id, 'Выберите пару валют', reply_markup=markup)
    else:
        bot.send_message(message.chat.id, 'Число должно быть положительным. Введите сумму', reply_markup=markup)
        bot.register_next_step_handler(message, summa)

@bot.callback_query_handler(func=lambda call: True)
def callback(call):
    if call.data != 'else':
        values = call.data.upper().split('/')
        res = currency.convert(amount, values[0], values[1])
        bot.send_message(call.message.chat.id, f'Получается: {round(res, 2)}. Можете написать другую сумму')
        bot.register_next_step_handler(call.message, summa)
    else:
        bot.send_message(call.message.chat.id, 'Введите наименования валют через знак "/"')
        bot.register_next_step_handler(call.message, my_currency)

def my_currency(message):
    try:
        values = call.data.upper().split('/')
        res = currency.convert(amount, values[0], values[1])
        bot.send_message(call.message.caht.id, f'Получается: {round(res, 2)}. Можете написать другую сумму')
        bot.register_next_step_handler(call.message, summa)
    except Exception:
        bot.send_message(message.chat.id, 'Вы ввели что-то не то. Впишите значение заново')
        bot.register_next_step_handler(message, my_currency)


bot.polling(none_stop=True)