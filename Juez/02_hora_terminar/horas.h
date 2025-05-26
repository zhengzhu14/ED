#ifndef horas_h
#define horas_h

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <iomanip>
using namespace std;
class horas {
public: 
	horas() {}
	horas(int h, int m, int s) {
		if (h < MAX_HOUR && h >= 0 && m < MAX_MIN_SEG && m >= 0 && s < MAX_MIN_SEG && s >= 0) {
			this->time = (h * SEG_HOUR) + (m * MAX_MIN_SEG) + s;
		}
		else {
			throw std::invalid_argument("Argumentos no validos");
		}
		
	}

	horas(int time) {
		this->time = time;
	}


	horas & operator= (horas const& h) {
		if (this != &h) {
			time = h.time;
		}
		return *this;
	}

	bool operator<(horas const& h2) {
		return time < h2.time;
	}
	bool operator ==(horas const& h2) {
		return time == h2.time;
	}
	horas operator+(horas const& h2) {
		int total = time + h2.time;
		if (total < SEG_DAY) {
			return horas(total);
		}
		else throw overflow_error("hoy no");
	}

	int get_time() const{ return time; }

	

private:
	const int MAX_HOUR = 24;
	const int MAX_MIN_SEG = 60;
	const int SEG_HOUR = 3600;
	const int SEG_DAY = 86400;
	int time;
};

inline std::istream& operator >>(istream & in, horas& h) {
	char aux;
	int hh, mm, ss;
	in >> hh >> aux >> mm >> aux >> ss;
	h = horas(hh, mm, ss);

	return in;
}

inline std::ostream& operator <<  (ostream& out, horas const& h)  {
	int hh, mm, ss;
	hh = h.get_time() / 3600;
	mm = (h.get_time() % 3600) / 60;
	ss = ((h.get_time() % 3600) % 60);
	out << fixed << setfill('0') << setw(2) << hh << ":" << setfill('0') << setw(2) << mm << ":" << setfill('0') << setw(2) << ss;
	return out;
}

#endif