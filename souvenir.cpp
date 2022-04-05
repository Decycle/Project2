#include "souvenir.h"

/**********************************************************
 *
 * CONSTRUCTOR souvenirs
 *_________________________________________________________
 * This constructor receives nothing and creates an empty
 * souvenirs object with capacity 100.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   empty souvenirs object with capacity 100 created
 ***********************************************************/
souvenirs::souvenirs(){
    _s = new souvenir[100];
    _capacity = 100;
    _size = 0;
}
/**********************************************************
 *
 * DESTRUCTOR ~souvenirs
 *_________________________________________________________
 * This destructor receives nothing and frees all memory
 * used by the array.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   Dynamic memory used by array is freed
 ***********************************************************/
souvenirs::~souvenirs(){
    delete [] _s;
}

/**********************************************************
 *
 * CONSTRUCTOR souvenirs
 *_________________________________________________________
 * This copy construcctor receives a reference to another
 * souvenirs object, and creates a new souvenirs object
 * identical to the parameter
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     other: souvenirs object to copy
 *
 * POST-CONDITIONS
 *   This function will create a new souvenirs object
 *   identical to the parameter
 ***********************************************************/
souvenirs::souvenirs(const souvenirs& other){
    _capacity = other._capacity;
    _s = new souvenir[_capacity];
    for(int i = 0; i < other._size; i++){
        _s[i] = other[i];
    }
}

/**********************************************************
 *
 * FUNCTION operator=
 *_________________________________________________________
 * This function receives a souvenirs object to copy from
 * and updates the calling souvenirs object to be identical
 * to the parameter
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     other: souvenirs object to copy
 *
 * POST-CONDITIONS
 *   This function will update the calling souvenirs object
 *   to be identical to the parameter
 ***********************************************************/
souvenirs& souvenirs::operator = (const souvenirs& other){
    if(_capacity < other._capacity){
        resize();
    }

    for(int i = 0; i < other._size; i++){
        _s[i] = other[i];
    }
}

/**********************************************************
 *
 * FUNCTION operator[]
 *_________________________________________________________
 * This function receives an index to a souvenir and returns
 * the souvenirs at the index.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     index: index of souvenir object
 *
 * POST-CONDITIONS
 *   This function will return the souvenir found at the
 *   given index.
 ***********************************************************/
souvenir& souvenirs::operator[](int index) const {
    return _s[index];
}

/**********************************************************
 *
 * FUNCTION addSouvenir
 *_________________________________________________________
 * This function receives a souvenir and adds it to the
 * array.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     addMe: souvenir to add to array
 *
 * POST-CONDITIONS
 *   This function will add the given souvenir to the array
 ***********************************************************/
void souvenirs::addSouvenir(souvenir addMe){
    if(_size == _capacity){
        resize();
    }
    _s[_size++] = addMe;
}

/**********************************************************
 *
 * FUNCTION removeSouvenir
 *_________________________________________________________
 * This function receives an index to the souvenir and
 * removes it from the array.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     index: index of souvenir to remove
 *
 * POST-CONDITIONS
 *   This function will remove the souvenir from the array
 ***********************************************************/
void souvenirs::removeSouvenir(int index){
    if(index < 0 || index >= _size){
        return; // error
    }

    _size--;
    for(int i = index; i < _size; i++){
        _s[i] = _s[i+1];
    }
}

/**********************************************************
 *
 * FUNCTION getItemCount
 *_________________________________________________________
 * This function receives a souvenir and returns the number
 * of occurrences of the souvenir in the array
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     itemName: souvenir to count
 *
 * POST-CONDITIONS
 *   This function will return the number of times the
 *   souvenir is found in the array.
 ***********************************************************/
int souvenirs::getItemCount(souvenir itemName) const {
    int count = 0;
    for(int i = 0; i < _size; i++){
        if(_s[i] == itemName){
            count++;
        }
    }

    return count;
}

/**********************************************************
 *
 * FUNCTION operator==
 *_________________________________________________________
 * This function receives a souvenirs object and returns
 * true if it is identical to the calling souvenir
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     other: souvenirs object to compare with
 *
 * POST-CONDITIONS
 *   This function will return true if the calling
 *   souvenirs object is identical to the parameter
 ***********************************************************/
bool souvenirs::operator == (const souvenirs& other){
    for(int i = 0; i < _size; i++){
        if(_s[i] != other[i]){
            return false;
        }
    }

    return true;
}

/**********************************************************
 *
 * FUNCTION resize
 *_________________________________________________________
 * This function receives nothing and doubles the size of
 * the array while maintaining its original order.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function will double the capacity of the array
 ***********************************************************/
void souvenirs::resize(){
    souvenir* temp = new souvenir[2*_capacity];
    for(int i = 0; i < _capacity; i++){
        temp[i] = _s[i];
    }

    delete [] _s;
    _s = temp;
}

/**********************************************************
 *
 * FUNCTION totalPrice
 *_________________________________________________________
 * This function receives nothing and returns the total
 * cost of all souvenirs in the array.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function will return the total cost of all
 *   souvenirs in the array.
 ***********************************************************/
std::string souvenirs::totalPrice() const {
    double total = 0.0;
    for(int i = 0; i < _size; i++){
        total += std::stod(_s[i].getPrice())*_s[i].getQuantity();
    }

    std::string stotal = "$" + std::to_string(total);
    stotal = stotal.substr(0, stotal.find('.')+3);

    return stotal;
}

/**********************************************************
 *
 * FUNCTION printReport
 *_________________________________________________________
 * This function receives nothing and prints the contents
 * of all souvenirs found in the array.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function will return all info of every souvenir in
 *   the array.
 ***********************************************************/
std::string souvenirs::printReport() const {
    std::string output = "----------Begin Report---------\n\n";
    if(_size == 0){
        output += "No Purchases Made";
    } else{
        for(int i = 0; i < _size; i++){
            output += "Name: ";
            output += _s[i].getName();
            output += "\nPrice: $";
            output += _s[i].getPrice();
            output += "\nQuantity Purchased: ";
            output += std::to_string(_s[i].getQuantity());
            output += "\n\n";
        }
    }
    output += "\n\n---------End Report---------";

    return output;
}

/**********************************************************
 *
 * FUNCTION getIndex
 *_________________________________________________________
 * This function receives a name and returns the index of
 * the souvenir with that name.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following must be predefined:
 *      name: name of souvenir to search for
 *
 * POST-CONDITIONS
 *   This function will return the index of the souvenir
 *   with the name, or -1 otherwise.
 ***********************************************************/
int souvenirs::getIndex(std::string name) const // IN - name to search
{
    for(int i = 0; i < _size; i++){
        if(_s[i].getName() == name){
            return i;
        }
    }

    return -1;
}

