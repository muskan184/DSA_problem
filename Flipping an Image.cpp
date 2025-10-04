class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n= image.size();
        int m = image[0].size();

        for(int i=0;i<n;i++){
            int lp=0,rp=m-1;

            while(lp <= rp) {
                if(lp == rp){
                image[i][lp] ^= 1;
                }else {
                    image[i][lp] ^= 1;
                    image[i][rp] ^= 1;
                    swap (image[i][lp],image[i][rp]);
                }
                lp++;
                rp--;
            }
        }
        return image;
    }
};
