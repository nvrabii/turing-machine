#include <iostream>

/**
 * mt supposes that the band has the good size and sufficient 0 offsets
 * 
 * "band" - array representing initial state of the band
 * "p" - intial pointer
 */
char* mt(char* band, int p) {

    int state = 0;

    while(true) {
        switch(state) {
            case 0:
                switch(band[p]) {
                    case '0':
                        band[p] = 's';
                        break;
                    case '1':
                        p--;
                        break;
                    case 's':
                        p++;
                        state = 1;
                        break;
                    default:
                        return band;
                }
                break;
            case 1:
                switch(band[p]) {
                    case '0':
                        state = 2;
                    case '1':
                        p++;
                        break;
                    default:
                        return band;
                }
                break;
            case 2:
                switch(band[p]) {
                    case '0':
                        p--;
                        state = 3;
                        break;
                    case '1':
                        p++;
                        state = 1;
                        break;
                    default:
                        return band;
                }
                break;
            case 3:
                switch(band[p]) {
                    case '0':
                        band[p] = 'e';
                        state = 4;
                        break;
                    default:
                        return band;
                }
                break;
            case 4:
                switch(band[p]) {
                    case '0':
                    case '1':
                    case 'e':
                        p--;
                        break;
                    case 's':
                        p++;
                        state = 5;
                        break;
                    default:
                        return band;
                }
                break;
            case 5:
                switch(band[p]) {
                    case '0':
                        p++;
                        break;
                    case '1':
                        band[p] = '0';
                        state = 6;
                        break;
                    default:
                        return band;
                }
                break;
            case 6:
                switch(band[p]) {
                    case '0':
                        p++;
                        state = 7;
                        break;
                    default:
                        return band;
                }
                break;
            case 7:
                switch(band[p]) {
                    case '0':
                        p++;
                        state = 8;
                        break;
                    case '1':
                        p++;
                        break;
                    case 'e':
                        p++;
                        state = 9;
                        break;
                    default:
                        return band;
                }
                break;
            case 8:
                switch(band[p]) {
                    case '0':
                        p++;
                        break;
                    case '1':
                        state = 5;
                        break;
                    case 'e':
                        p++;
                        state = 9;
                        break;
                    default:
                        return band;
                }
                break;
            case 9:
                switch(band[p]) {
                    case '0':
                        band[p] = '1';
                        state = 4;
                        break;
                    case '1':
                        p++;
                        break;
                    default:
                        return band;
                }
                break;
            default:
                return band;
        }
    }

    return band;
}

int main() {
    char* test_0 = (char *) malloc(sizeof(char) * 32);
    strcpy(test_0, "000101111101100000000");

    std::cout << mt(test_0, 3) << '\n';
}