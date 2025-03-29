#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, x1, y1, x2, y2;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;

        // Calculate delta ranges for A
        ll delta_x_min_A = 1 - x1;
        ll delta_x_max_A = n - x1;
        ll delta_y_min_A = 1 - y1;
        ll delta_y_max_A = m - y1;

        // Calculate delta ranges for B
        ll delta_x_min_B = 1 - x2;
        ll delta_x_max_B = n - x2;
        ll delta_y_min_B = 1 - y2;
        ll delta_y_max_B = m - y2;

        // Calculate number of valid shifts |shifts|
        ll shift_x_min = max(delta_x_min_A, delta_x_min_B);
        ll shift_x_max = min(delta_x_max_A, delta_x_max_B);
        ll count_shifts_x = (shift_x_max >= shift_x_min) ? (shift_x_max - shift_x_min + 1) : 0;

        ll shift_y_min = max(delta_y_min_A, delta_y_min_B);
        ll shift_y_max = min(delta_y_max_A, delta_y_max_B);
        ll count_shifts_y = (shift_y_max >= shift_y_min) ? (shift_y_max - shift_y_min + 1) : 0;

        ll shifts = count_shifts_x * count_shifts_y;

        // Calculate |A ∩ B|
        // Adjusted delta ranges for intersection
        ll adjusted_dx_min = delta_x_min_B + (x1 - x2);
        ll adjusted_dx_max = delta_x_max_B + (x1 - x2);
        ll adjusted_dy_min = delta_y_min_B + (y1 - y2);
        ll adjusted_dy_max = delta_y_max_B + (y1 - y2);

        // Count valid dx for intersection
        ll inter_shift_x_min = max(delta_x_min_A, adjusted_dx_min);
        ll inter_shift_x_max = min(delta_x_max_A, adjusted_dx_max);
        ll count_inter_x = (inter_shift_x_max >= inter_shift_x_min) ? (inter_shift_x_max - inter_shift_x_min + 1) : 0;

        // Count valid dy for intersection
        ll inter_shift_y_min = max(delta_y_min_A, adjusted_dy_min);
        ll inter_shift_y_max = min(delta_y_max_A, adjusted_dy_max);
        ll count_inter_y = (inter_shift_y_max >= inter_shift_y_min) ? (inter_shift_y_max - inter_shift_y_min + 1) : 0;

        ll intersect = count_inter_x * count_inter_y;

        // Calculate number of cells not melted
        // Total cells melted: 2 * shifts - intersect
        // Cells not melted: n * m - (2 * shifts - intersect)
        ll total_cells = n * m;
        ll melted = 2 * shifts - intersect;
        ll not_melted = total_cells - melted;

        cout << not_melted << "\n";
    }
}