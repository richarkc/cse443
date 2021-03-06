// Copyright (C) 2016 Kyle Richardson

#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

void putChar(std::string& s, const int targetPos,
  const int oldPos, const char c, const int num) {
    // two seperate cases for before and after gather pos
    if (oldPos < targetPos) {
        for (int i = oldPos; i < targetPos - 1; i++) {
          s[i] = s[i + 1];
        }
    // move the next character after the gather before it to maintain weight
    s[targetPos - 1] = s[targetPos + num];
    s[targetPos + num] = c;
    } else if (targetPos < oldPos) {
        for (int i = oldPos; i > (targetPos + num); i--) {
          s[i] = s[i - 1];
        }
        s[targetPos + num] = c;
    }
}

void gatherDigits(std::string& s, const int pos) {
  int num = 0;
  // i cannot be negative, so unsigned cast for comparison
  for (int i = 0; (unsigned)i < s.length(); i++) {
    // ignore all ints already "gathered"
    if (i >= pos && i < (pos + num)) {
      continue;
    }
        if (std::isdigit(s[i])) {
            putChar(s, pos, i, s[i], num);
            num++;
      // ensure case where 2 ints next to each other will still
      // be checked when swapped
      if (i < pos)
        i--;
        }
    }
}



// --------------------------------------------------------------
//        DO  NOT  MODIFY  CODE  BELOW  THIS  LINE
// --------------------------------------------------------------

int main() {
    std::string str;
    int pos = 0;
    do {
        std::cout << "Enter gather position (-1 to quit) and string:\n";
        std::cin >> pos;
        if (pos != -1) {
            std::cin >> str;
            gatherDigits(str, pos);
            std::cout << "Gathered @ " << pos << ": " << str << std::endl;
        }
    } while (pos != -1);
    return 0;
}
