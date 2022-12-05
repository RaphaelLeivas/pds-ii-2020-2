#ifndef GET_MAX_H
#define GET_MAX_H

#include <iostream>
#include <cmath>

using namespace std;

/**
 * \brief This class represents a bit set, that is, a set represented as a map
 * of bits. The set has capacity to store 32 elements. For instance, the set
 * <||||----------------------------> is the binary representation of the number
 * 15, and it means that the elements 1, 2, 3 and 4 are in the set. Similarly,
 * the set <--||----------------------------> is the binary representation of
 * the number 12, and it means that the elements 3 and 4 are in the set.
 */
struct BitSet {
  BitSet(unsigned value): _set(value) {} // construtor da classe
  const unsigned _set;
  friend std::ostream & operator<<(std::ostream& os, const BitSet& i) { // definição do operador << para o cout
    const int limit = sizeof(unsigned) * 8;
    os << '<';
    for (int aux = 0; aux < limit; aux++) {
      unsigned mask = 1 << aux;
      if (i._set & mask) {
        os << "|";
      } else {
        os << "-";
      }
    }
    os << '>';
    return os;
  };

  /**
   * \brief compares two bit sets. A bit set b1 is greater than or equal to
   * another bit set b2 if b1 contains all the bits in b2. For instance, the
   * bit set represented by 15 is greater than the bit set represented by 12.
   * However, the bit set 6 is not greater than the bit set 3, because the
   * former does not contain the first element, which is in the latter.
   * \return true if bit_set1 is greater than bit_set2
   */
  bool operator >= (const struct BitSet&obj) {
    // vetores de representação binaria dos dois sets
    int binSet1[32];
    int binSet2[32];

    // converte o primeiro set
    int decSet1 = this->_set;
    for(int i = 31; i >= 0; --i) {
      if(decSet1 >= pow(2, i)) {
        binSet1[i] = 1;
        decSet1 -= pow(2, i);
      } else {
        binSet1[i] = 0;
      }
    }

    // converte o segundo set
    int decSet2 = obj._set;
    for(int i = 31; i >= 0; --i) {
      if(decSet2 >= pow(2, i)) {
        binSet2[i] = 1;
        decSet2 -= pow(2, i);
      } else {
        binSet2[i] = 0;
      }
    }

    // agora temos que ver se bitSet1 contem bitSet2
    // se set1 contem set2, temos que set1 contem todos os bits
    // ATIVOS de set2.
    for(int i = 0; i < 32; ++i) {
      if(binSet2[i] == 1 && binSet1[i] == 0) {
        return false;
      }
    }

    return true;
  }

};

/**
 * \brief The representation of an integer interval. An integer interval has a
 * lower bound (a left side), and an upper bound (a right side). For instance,
 * the interval (2, 6) contains all the elements from 2 to 6, including these
 * two.
 */
struct Interval {
  Interval(int left, int right): _l(left), _r(right) {} // construtor da classe
  const int _l;
  const int _r;
  friend std::ostream & operator<<(std::ostream& os, const Interval& i) {
    os << '(' << i._l << ", " << i._r << ')';
    return os;
  }


  /**
   * \brief compares two intervals to see if the first is greater than or equal
   * the second. An interval (a1, a2) is greater than or equal another interval
   * (b1, b2) if a1 <= b1 and a2 >= b2.
   * \return true if interval1 is greater than or equal interval2
   */
  bool operator >= (const struct Interval& obj) {
    // I1 só é maior que I2 se, e somente se, 
    //  - I1_l < I2_l e
    //  - I1_r > I2_r
    if(this->_l > obj._l || this->_r < obj._r){
      return false;
    } else {
      return true;
    }
  }
};

/**
 * \brief Returns the greatest of two elements, or a default, if neither of
 * them is the greatest.
 */
template <class T>
T GetMaxDefault (T a, T b, T dflt) {
  if(a >= b) return a;
  else if (b >= a) return b;
  else return dflt;
}

#endif