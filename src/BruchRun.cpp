#include <iostream>
#include <vector>
#include "Bruch.h"


int main() {
    Bruch eins{ 5, 3 };
    Bruch zwei{ 1, 3 };
    Bruch drei{ 2, 7 };
    drei = eins;
    Bruch vier;
    vier = eins + drei;
    Bruch fuenf = eins / zwei;
    vier += fuenf;
    Bruch sechs = fuenf;
    Bruch sieben = Bruch{ 2, 9 };
    sieben = Bruch{ 3, 7 };
    sechs = vier - fuenf;
    Bruch acht(vier);
    Bruch neun(7);

    Bruch a1(3, 7);
    Bruch a2{ 6, 14 };
    Bruch a3 = { 3, 6 };
    Bruch a4 = { 2, 4 };
    //Bruch a4 = (2, 4); // error: keine Konvertierung von int nach Bruch
    Bruch a5 = Bruch(5);
    //Bruch b1 = 6; // error: copy-initialization does not consider Bruch::Bruch(int)

    std::vector<Bruch> bruchVec;
    bruchVec.push_back(a1);
    bruchVec.push_back(a2);
    bruchVec.push_back(a3);
    bruchVec.push_back(a4);
    bruchVec.push_back(eins);
    bruchVec.push_back(zwei);
    bruchVec.push_back(drei);
    bruchVec.push_back(vier);
    bruchVec.push_back(fuenf);
    bruchVec.push_back(sechs);
    bruchVec.push_back(sieben);
    bruchVec.push_back(acht);
    bruchVec.push_back(neun);

    for(auto const& elem : bruchVec) {
      std::cout << elem << std::endl;
    }

    /*
    auto sortRuleLambda = [] (Bruch const& b1, Bruch const& b2) -> bool {
      return b1 < b2;
    };

    std::sort(bruchVec.begin(), bruchVec.end(), sortRuleLambda);
    */

    std::sort(bruchVec.begin(), bruchVec.end(), [] (Bruch const& b1, Bruch const& b2) -> bool { return b1 < b2; });

    std::cout << "***************************************\n";

    for(auto const& elem : bruchVec) {
      std::cout << elem << std::endl;
    }
}
