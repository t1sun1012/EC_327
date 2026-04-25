#include <iostream>
#include <iomanip>

#include "View.h"

using namespace std;

View::View()
{
    size = 11;
    scale = 2;
}

void View::Clear()
{
    for (int i = 0; i < view_maxsize; i++) {
        for (int j = 0; j < view_maxsize; j++) {
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
}

bool View::GetSubscripts(int& out_x, int& out_y, Point2D location)
{
    Vector2D offset = (location - origin) / scale;

    out_x = static_cast<int>(offset.x);
    out_y = static_cast<int>(offset.y);

    if (out_x >= 0 && out_x < size && out_y >= 0 && out_y < size) {
        return true;
    }

    cout << "An object is outside the display" << endl;
    return false;
}

void View::Plot(GameObject* ptr)
{
    int ix;
    int iy;

    if (!ptr->ShouldBeVisible()) {
        return;
    }

    if (GetSubscripts(ix, iy, ptr->GetLocation())) {
        // A collision is shown by replacing the cell with "* ".
        if (grid[iy][ix][0] == '.') {
            ptr->DrawSelf(grid[iy][ix]);
        }
        else {
            grid[iy][ix][0] = '*';
            grid[iy][ix][1] = ' ';
        }
    }
}

void View::Draw()
{
    ios::fmtflags old_flags = cout.flags();
    streamsize old_precision = cout.precision();

    // The grid is drawn top-down so larger y values appear higher on the screen.
    cout << "Display size: " << size << ", scale: " << scale << ", origin: " << origin << endl;

    cout << "  ";
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            cout << setw(4) << fixed << setprecision(0) << (origin.x + i * scale);
        }
        else {
            cout << "    ";
        }
    }
    cout << endl;

    for (int i = size - 1; i >= 0; i--) {
        if (i % 2 == 0) {
            cout << setw(2) << fixed << setprecision(0) << (origin.y + i * scale) << " ";
        }
        else {
            cout << "   ";
        }

        for (int j = 0; j < size; j++) {
            cout << grid[i][j][0] << grid[i][j][1];
        }
        cout << endl;
    }

    cout.flags(old_flags);
    cout.precision(old_precision);
}
