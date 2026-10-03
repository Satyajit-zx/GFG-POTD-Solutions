class Solution {
public:
    vector<vector<int>> formCoils(int n) {
        int size = 4 * n;
        int total = size * size;

        vector<int> coil1;
        vector<int> coil2;

        for (int ring = 0; ring < size / 2; ring++) {
            int lo = ring;
            int hi = size - 1 - ring;

            if (ring % 2 == 0) {
                // Down along left side
                for (int r = lo; r <= hi; r++) {
                    coil1.push_back(r * size + lo + 1);
                }

                // Right along bottom
                for (int c = lo + 1; c < hi; c++) {
                    coil1.push_back(hi * size + c + 1);
                }
            }
            else {
                // Up along right side
                for (int r = hi; r >= lo; r--) {
                    coil1.push_back(r * size + hi + 1);
                }

                // Left along top
                for (int c = hi - 1; c > lo; c--) {
                    coil1.push_back(lo * size + c + 1);
                }
            }
        }

        // Second coil
        for (int x : coil1) {
            coil2.push_back(total + 1 - x);
        }

        return {coil1, coil2};
    }
};
