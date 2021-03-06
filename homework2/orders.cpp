#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "order.h"


using namespace std;

Order::Order(char * s, char bs, double p, int q, char mp, int oid)
{
	if (p > 0.0) {
		price = p;
	}
	if (q > 0) {
		quantity = q;
	}
	if (oid > 0) {
		order_id = oid;
	}
	if (s != NULL) {
		sym = new char[strlen(s) + 1];
		strcpy(sym, s);
	}
	if (bs != '\0') {
		side = bs;
	}
	if (mp != '\0') {
		message_type = mp;
	}
}

Order::~Order() {
	if (price != 0.0) {
		price = 0.0;
	}
	if (quantity != 0) {
		quantity = 0;
	}
	if (order_id != 0) {
		order_id = 0;
	}
	if (sym != NULL) {
		delete sym;
	}
	if (side != '\0') {
		side = '\0';
	}
	if (message_type != '\0') {
		message_type = '\0';
	}
}

bool Order::set_symbol(char * s) {
	if (sym != NULL) {
		delete[] sym;
	}
	sym = new char[strlen(s) + 1];
	strcpy(sym, s);
	return true;
}

bool Order::set_side(char s)
{
	if (s != '\0') {
		side = s;
		return true;
	}
	return false;
}

bool Order::set_orderid(int oid)
{

	if (oid != 0) {
		order_id = oid;
		return true;
	}
	return false;
}

bool Order::set_message_type(char mp)
{
	if (mp != '\0') {
		message_type = mp;
		return true;
	}
	return false;
}

bool Order::set_quantity(int q)
{
	if (q != 0) {
		quantity = q;
		return true;
	}
	return false;
}

bool Order::set_price(double p)
{
	if (p != 0.0) {
		price = p;
		return true;
	}
	return false;
}

char * Order::get_symbol() {
	return sym;
}

char Order::get_side() {
	return side;
}

double Order::get_price()
{
	return price;
}

int Order::get_quantity()
{
	return quantity;
}

char Order::get_message_type() {
	return message_type;
}

char Order::get_order_id() {
	return order_id;
}
void Order::write_console() {
	cout << endl;
	if (price <= 0.0 || quantity <= 0 || order_id <= 0 || sym == NULL || side == '\0' || message_type == '\0') {
		cout << "Not all data points are available, can't print!" << endl;
	}
	else {
		cout << "MsgType: " << message_type << " Sym : " << sym << " Side : " << side << " Quantity : " << quantity << " Price : " << price << " OrderId : " << order_id << endl;
	}
}

void Order::count_msg_types(Order **& orders, int num_orders) {
	cout << endl;
	int a = 0; int m = 0; int d = 0; int c = 0;
	char mp;
	char *msg;
	msg = new char[1];

	for (int j=0; j < num_orders; j++) {
		msg[0] = 'A';
		msg[1] = 'A';
		msg[2] = 'A';
		msg[3] = 'M';
		msg[4] = 'A';
		msg[5] = 'M';
		msg[6] = 'D';
		mp = msg[j];
		switch (mp) {
		case 'A':
			a++;
			break;
		case 'M':
			m++;
			break;
		case 'D':
			d++;
			break;
		case 'C':
			c++;
			break;
		}
	}		
	cout << "Add Msg : " << a << " Modify Msg : " << m << " Delete Msg : " << d << " Clear Msg : " << c << endl;
}
