#include "../.h/reservoirs.h"

reservoirs::reservoirs(std::string name, std::string municipality, int id, std::string code, double maxDelivery)
        : name(name), municipality(municipality), id(id), code(code), maxDelivery(maxDelivery) {}

std::string reservoirs::getName() {return name;}
std::string reservoirs::getMunicipality() {return municipality;}
int reservoirs::getId() {return id;}
std::string reservoirs::getCode() {return code;}
double reservoirs::getMaxDel() {return maxDelivery;}

