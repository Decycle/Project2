#ifndef SOUVENIR_H
#define SOUVENIR_H

#include <string>

struct souvenir{
    /*****************
     ** CONSTRUCTOR **
     *****************/
    souvenir(){}

    souvenir(std::string name,         // IN -  name of souvenir
             std::string price,        // IN - price of souvenir
             std::string description){ // IN - description of souvenir
        _name = name;
        _price = price;
        _description = description;
        _quantity = 0;
    }

    /****************
     ** ACCESSORS **
     ****************/
    bool operator==(const souvenir& s){ return _name == s._name && _price == s._price; }
    bool operator!=(const souvenir& s){ return !(*this == s); };

    std::string getName() const {
        return _name;
    }

    std::string getPrice() const {
        return _price;
    }

    std::string getDescription() const {
        return _description;
    }

    int getQuantity() const {
        return _quantity;
    }

    /**************
     ** MUTATORS **
     **************/
    void setName(std::string name){  // IN -  name of souvenir
        _name = name;
    }

    void setPrice(std::string price){    // IN -  price of souvenir
        _price = price;
    }

    void setDescription(std::string description){    // IN -  description of souvenir
        _description = description;
    }

    void setQuantity(int quantity){
        _quantity = quantity;
    }

    void addQuantity(){
        _quantity++;
    }

private:
    std::string _name;       //ATT- name of souvenir
    std::string _price;      //ATT- price of souvenir
    std::string _description;      //ATT- description of souvenir
    int _quantity = 0; // number of souvenirs bought
};

/****************************************************************
 * souvenirs struct
 *   This struct represents a souvenir. It manages 3 attributes,
 *   name, price and description.
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * souvenirs();
 *   Constructor; creates an empty souvenir struct
 *   Parameters: none
 *   Return: none
 ***************************************************************/

/****************************************************************
 *   souvenir(std::string name,
             std::string price,
             std::string description);
 *   Constructor; creates souvenir with given parameters
 *   Parameters:
 *           std::string name        // IN - name of souvenir
 *           std::string price       // IN - price of souvenir
 *           std::string description // IN - description of souvenir
 *   Return: none
 ***************************************************************/


 /***************
  ** ACCESSORS **
  ***************/

/****************************************************************
 * bool operator==(const souvenir& s);
 *
 *   Accessor; This method will return true if the given parameter
 *             is the same as the calling souvenir.
 * --------------------------------------------------------------
 *   Parameters:
 *             const souvenir& s // IN - souvenir to compare
 * --------------------------------------------------------------
 *   Return: bool - true if the same, false otherwise
 ***************************************************************/

/****************************************************************
 * bool operator!=(const souvenir& s);
 *
 *   Accessor; This method will return true if the given parameter
 *             is not the same as the calling souvenir.
 * --------------------------------------------------------------
 *   Parameters:
 *             const souvenir& s // IN - souvenir to compare
 * --------------------------------------------------------------
 *   Return: bool - true if not the same, false otherwise
 ***************************************************************/

/****************************************************************
 * std::string getName() const;
 *
 *   Accessor; This method will return the name of the souvenir
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _name (std::string) // name of souvenir
 ***************************************************************/

/****************************************************************
 * std::string getPrice() const;
 *
 *   Accessor; This method will return the price of the souvenir
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _price (std::string) // price of souvenir
 ***************************************************************/

/****************************************************************
 * std::string getDescription() const;
 *
 *   Accessor; This method will return the description of the
 *             souvenir
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _description (std::string) // description of souvenir
 ***************************************************************/

/****************************************************************
 * std::string getQuantity() const;
 *
 *   Accessor; This method will return the quantity of the
 *             souvenir
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _quantity (int) // quantity of souvenir
 ***************************************************************/


/**************
 ** MUTATORS **
 **************/

/*******************************************************************
 * void setName(std:string name);
 *
 *   Mutator; This method will update the name attribute to the
 *            parameter name
 *------------------------------------------------------------------
 *   Parameter: name (std::string) // IN – new name
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void setPrice(std:string price);
 *
 *   Mutator; This method will update the price attribute to the
 *            parameter price
 *------------------------------------------------------------------
 *   Parameter: price (std::string) // IN – new price
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void setDescription(std:string description);
 *
 *   Mutator; This method will update the description attribute to the
 *            parameter description
 *------------------------------------------------------------------
 *   Parameter: description (std::string) // IN – new description
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void setQuantity(std:string quantity);
 *
 *   Mutator; This method will update the quantity attribute to the
 *            parameter quantity
 *------------------------------------------------------------------
 *   Parameter: quantity (std::string) // IN – new quantity
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void addQuantity();
 *
 *   Mutator; This method will add one to the quantity attribute
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/


class souvenirs
{
public:
    /**********************************
     ** CONSTRUCTORS AND DESTRUCTORS **
     **********************************/
    souvenirs();

    ~souvenirs();

    souvenirs(const souvenirs& other); // IN -  souvenir arr to copy

    /**************
     ** MUTATORS **
     **************/
    souvenirs& operator = (const souvenirs& other); //IN -  souvenir arr to copy

    void addSouvenir(souvenir);     // IN -  souvenir to add to arr

    void removeSouvenir(int index); // IN -  index of souv to rem

    void resize();

    /***************
     ** ACCESSORS **
     ***************/
    std::string printReport() const;

    souvenir& operator [](int index) const ;        // IN -  index to access

    bool operator == (const souvenirs& other);

    int getSize() const { return _size; };

    int getItemCount(souvenir itemName) const;

    std::string totalPrice() const;

    int getIndex(std::string name) const;
private:
    souvenir* _s;   //ATT - souvenir array
    int _size;      //ATT - number of souvenirs
    int _capacity;
};

/****************************************************************
 * souvenirs Class
 *   This class represents a souvenirs object. It manages 4
 *   attributes: _s (array of souvenir), _size and _capacity
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * souvenirs();
 *   Constructor; Initialize an empty souvenirs class
 *   Parameters: none
 *   Return: none
 ***************************************************************/

/****************************************************************
 * souvenirs(const souvenirs& other);
 *   Constructor; Initialize a souvenirs class that is identical
 *                to the parameter
 *   Parameters: const souvenirs& other // IN - souvenirs to copy
 *   Return: none
 ***************************************************************/

/****************************************************************
 * ~souvenirs();
 *   Destructor; Frees all dynamically allocated memory
 *   Parameters: none
 *   Return: none
 ***************************************************************/


/**************
 ** MUTATORS **
 **************/

/*******************************************************************
 * souvenirs& operator=(const souvenirs& other);
 *
 *   Mutator; This method will make the calling souvenirs object
 *            identical to the parameter
 *------------------------------------------------------------------
 *   Parameter: other (const souvenirs&) // IN – souvenirs to copy
 *------------------------------------------------------------------
 *   Return: reference to updated souvenirs object
 *******************************************************************/

/*******************************************************************
 * void addSouvenir(souvenir);
 *
 *   Mutator; This method will add the given souvenir to the end
 *            of the array _s.
 *------------------------------------------------------------------
 *   Parameter: s (souvenir) // IN – souvenir to add
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void removeSouvenir(int index);
 *
 *   Mutator; This method will remove the souvenir found at the
 *            given index
 *------------------------------------------------------------------
 *   Parameter: index (int) // IN – souvenir to remove
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void resize();
 *
 *   Mutator; This method will resize the array if it runs out of
 *            space
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/


 /***************
  ** ACCESSORS **
  ***************/

/****************************************************************
 * std::string printReport() const;
 *
 *   Accessor; This method will print all info to the screen
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: std::string - all souvenirs in the object
 ***************************************************************/

/****************************************************************
 * souvenir& operator[](int index) const;
 *
 *   Accessor; This method will return the souvenir found at
 *             the given index.
 * --------------------------------------------------------------
 *   Parameters: index (int) // IN - index of souvenir in array
 * --------------------------------------------------------------
 *   Return: souvenir& - reference to souvenir at index
 ***************************************************************/

/****************************************************************
 * bool operator==(const souvenirs& other);
 *
 *   Accessor; This method will return true if the given souvenir
 *             is the same as the calling souvenir
 * --------------------------------------------------------------
 *   Parameters: other (souvenirs&) // IN - souvenir to compare
 * --------------------------------------------------------------
 *   Return: bool - true if identical false otherwise
 ***************************************************************/

/****************************************************************
 * int getSize() const;
 *
 *   Accessor; This method will return the number of souvenirs
 *             held in the array.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _size (int) // number of souvenirs
 ***************************************************************/

/****************************************************************
 * int getItemCount(souvenir itemName) const;
 *
 *   Accessor; This method will count the number of occurrences
 *             of the souvenir in the array.
 * --------------------------------------------------------------
 *   Parameters: itemName (souvenir) // IN - souvenir to find
 * --------------------------------------------------------------
 *   Return: int // number of occurrences of the souvenir
 ***************************************************************/

/****************************************************************
 * std::string totalPrice() const;
 *
 *   Accessor; This method will return the total price of all
 *             souvenirs in the array.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: std::string // total cost of all souvenirs in array
 ***************************************************************/

#endif // SOUVENIR_H
