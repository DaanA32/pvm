int* min(int* x, int* y, int* z){
    if(*x < *y && *x < *z){
        return x;
    }
    if(*y < *x && *y < *z){
        return y;
    }
    if(*z < *x && *z < *y){
        return z;
    }
    return nullptr;
}