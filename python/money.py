
# class Money(object):
#     def __init__(self, dollars, cents):
#         self.total_cents = dollars * 100 + cents

#     # Getter and setter for dollars...
#     @property
#     def dollars(self):
#         return self.total_cents // 100;
#     @dollars.setter
#     def dollars(self, new_dollars):
#         self.total_cents = 100 * new_dollars + self.cents

#     # And the getter and setter for cents.
#     @property
#     def cents(self):
#         return self.total_cents % 100;
#     @cents.setter
#     def cents(self, new_cents):
#         self.total_cents = 100 * self.dollars + new_cents



# money = Money(27, 12)
# message = "I have {:d} dollars and {:d} cents."
# print(message.format(money.dollars, money.cents))
# # "I have 27 dollars and 12 cents."

# money.dollars += 2
# money.cents += 20
# print(message.format(money.dollars, money.cents))
# # "I have 29 dollars and 32 cents."

# money.cents += 112
# print(message.format(money.dollars, money.cents))
# # "I have 30 dollars and 44 cents."


class Money(object):
    def __init__(self, dollars, cents):
        self.total_cents = dollars * 100 + cents

    # Getter and setter for dollars...
    @property
    def dollars(self):
        print("before out dollar",self.total_cents)
        return self.total_cents // 100;
    @dollars.setter
    def dollars(self, new_dollars):
        print("before set dollar",self.total_cents)
        self.total_cents = 100 * new_dollars + self.cents
        print("before after dollar",self.total_cents)

    # And the getter and setter for cents.
    @property
    def cents(self):
        print("before out cnets",self.total_cents)
        return self.total_cents % 100;
    @cents.setter
    def cents(self, new_cents):
        print("before set cents",self.total_cents)
        self.total_cents = 100 * self.dollars + new_cents
        print("after out cents",self.total_cents)



money = Money(27, 12)
message = "I have {:d} dollars and {:d} cents."
print(message.format(money.dollars, money.cents))
# "I have 27 dollars and 12 cents."
print("aaaa:",money.total_cents)

money.dollars += 2
money.cents += 20
print(message.format(money.dollars, money.cents))
# "I have 29 dollars and 32 cents."
print("bbbb:",money.total_cents)

#money.dollars += 1
money.cents += 112
print(message.format(money.dollars, money.cents),money.total_cents)
# "I have 30 dollars and 44 cents."
print("cccc:",money.total_cents)