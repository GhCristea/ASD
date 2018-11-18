#pragma once

#include<iostream>

template<typename T>
class Cella
{
public:
	//tipi
	using info_type = T;
	////////////typedef Cella<T>* position;
	//costruttori
	Cella() { _Lson = _Rson = _dad = nullptr; }
	Cella(info_type& );
	
	info_type _getInfo()const { return _info; }
	Cella<info_type>* _getLson()const { return _Lson; }
	Cella<info_type>* _getRson()const { return _Rson; }
	Cella<info_type>* _getDad()const { return _dad; }

	void _setInfo(info_type infIn) { _info = infIn; }
	void _setLson(Cella<info_type>* sonIn) { _Lson = sonIn; }
	void _setRson(Cella<info_type>* sonIn) { _Rson = sonIn; }
	void _setDad(Cella<info_type>* dadIn) { _dad = dadIn; }

private:
	info_type _info;
	Cella<info_type>* _dad;
	Cella<info_type>* _Lson;
	Cella<info_type>* _Rson;
};

template<typename T>
Cella<T>::Cella(info_type& infIn)
{
	_Lson = _Rson = _dad = nullptr;
	_info = infIn;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, Cella<T>* c) {
	cout << c->_getInfo();
	return out;
}