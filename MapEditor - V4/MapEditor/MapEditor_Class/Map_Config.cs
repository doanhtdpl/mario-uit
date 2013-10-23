/* 
File lưu trữ các biến để tùy chỉnh 
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace MapEditor
{ 
    public class Map_Const
    {
        public static int imgSelect = 0;
        //Xác lập chiều dài và rộng đối tượng trên Map
        public static int Height = 40;
        public static int Width = 40;
        //xac dinh chieu dai cua map
        public static int Map_Height = 0;
        public static int Map_Width = 0;
        //Thiết lập màu
        public static Color Grid_Color = Color.White;
        public static Color Background = Color.FromArgb(65, 128, 190);
        //Số lượng phần tử trong ma trận Matrix[y,x]
        public static int X;
        public static int Y;
        //Phần tử mặc định ban đầu của map
        public static int Default = 0;
    }
}
