int n;

int t[n];
int sorted[n-1];

for(t[int i]){
    int insertionIndex=0;
    while(sorted[insertionIndex] ≥ 0 && t[i] ≥ sorted[insertionIndex]){
        insertionIndex = insertionIndex + 1
    }
    sorted.insert(insertionIndex, t[i])
}

