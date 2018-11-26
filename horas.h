#pragma once
#ifndef Tren_h
#define Tren_h
#include <cstddef> // size_t
#include <iomanip>
#include <stdexcept>
#include <iostream>
class horas
{
private:
	int h;
	int m;
	int s;
	static bool check(int H, int M, int S) {
		return(H >=0 && H < 24 && M >= 0 && M < 60 && S >= 0 && S < 60);
	}
public:
	horas(int H = 0, int M = 0, int S = 0) {
		if (check(H, M, S)) {
			h = H; m = M; s = S;
		}
		else {
			throw std::invalid_argument("Hora no válida");
		}
	}
	bool operator<(horas const& that) const {
		return (h < that.h || (h == that.h && m < that.m) || (h == that.h && m == that.m && s < that.s));
	}
	bool operator==(horas const&that) const {
		return(h == that.h && m == that.m && s == that.s);
	}
	horas  operator+(horas const &that) const {
		horas r;
		int aux;
		aux = s + that.s;
		if (aux < 60) {
			r.s = aux; 
			aux = m + that.m;
		}
		else { 
			r.s = aux - 60;
			aux = m + that.m+1;
		}
		if (aux < 60) {
			r.m = aux;
			aux = h + that.h;
		}
		else {
			r.m = aux - 60;
			aux = h + that.h + 1;
		}
		if (aux >= 24) throw std::invalid_argument("La suma se nos fue de las manos");
		r.h = aux;
		return(r);
	}
	void read(std::istream& o = std::cin) {
		char c;
		int H, M, S;
		std::cin >> H >> c >> M >> c >> S;
		if (check(H, M, S)) {
			h = H; m = M; s = S;
		}
		else throw std::invalid_argument("Hora no válida");
	}
	void print(std::ostream& o = std::cout) const {
		o << std::setfill('0') << std::setw(2) << h << ':'
			<< std::setfill('0') << std::setw(2) << m << ':'
			<< std::setfill('0') << std::setw(2) << s;
	}
};
	 inline std::ostream & operator<<(std::ostream & out, horas const& h) {
		 h.print(out);
		 return out;
	 }
	 inline std::istream & operator>>(std::istream & entrada, horas & h) {
		 h.read(entrada);
		 return entrada;
	 }
#endif
