#include<cstring>
#include<cmath>
class BigInt {
private:
	char number[102];
public:
	BigInt() {}
	BigInt(char* anum) {
		strcpy(number, anum);
	}
	BigInt(BigInt &b) {
		strcpy(this->number, b.number);
	}
	friend istream& operator>>(istream& in, BigInt &c);
	friend ostream& operator<<(ostream& out, BigInt &c);
	friend BigInt operator+(BigInt a, BigInt b);
};

BigInt operator+(BigInt a, BigInt b) {
	size_t sizeA = strlen(a.number);
	size_t sizeB = strlen(b.number);
	size_t bigone = (sizeA >= sizeB) ? (sizeA) : (sizeB);
	char * resultString = new char[bigone + 2];

	int temp = 0;
	int i, j, k;
	bool isCarry = false;
	resultString[0] = '0';
	resultString[bigone + 1] = '\0';
	for (i = sizeA - 1, j = sizeB - 1, k = bigone; k >= 0; --i, --j, --k) {
		if (i >= 0 && j >= 0) {
			temp = a.number[i] + b.number[j] - '0' - '0';
			if (isCarry == true) {
				temp += 1;
				isCarry = false;
			}
			if (temp >= 10) {
				temp -= 10;
				isCarry = true;
			}
			resultString[k] = temp + '0';
		}
		else if (i >= 0 && j < 0) {
			temp = a.number[i] - '0';
			if (isCarry == true) {
				temp += 1;
				isCarry = false;
			}
			if (temp >= 10) {
				temp -= 10;
				isCarry = true;
			}
			resultString[k] = temp + '0';
		}
		else if (i < 0 && j >= 0) {
			temp = b.number[j] - '0';
			if (isCarry == true) {
				temp += 1;
				isCarry = false;
			}
			if (temp >= 10) {
				temp -= 10;
				isCarry = true;
			}
			resultString[k] = temp + '0';
		}
		else if (i < 0 && j < 0) {
		if (isCarry == true&&(a.number[0]!='0'&&b.number[0]!='0')) {
				resultString[k] = 1 + '0';
			}
			else {
				resultString[k] = '0';
			}
		}
	}

	BigInt res(resultString);
	return res;
}

istream& operator>>(istream& in, BigInt &c) {
	in >> c.number;
	return in;
}

ostream& operator<<(ostream& out, BigInt &c) {
	size_t len = strlen(c.number);
	unsigned int i = 0;
while (c.number[i] == '0') {
		i++;
	}
	if (i == len) {
		out << '0';
	}
	for (; i < len; ++i) {
		out << c.number[i];
	}
	return out;
}
