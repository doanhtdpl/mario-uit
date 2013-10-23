using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Windows.Forms;

namespace MapEditor
{
    class Map_Object
    {
        private Image Img;
        private Panel Map;

        public Map_Object(Image img, Panel pnl)
        {
            this.Img = img;
            this.Map = pnl;
        }

        //Vẽ đối tượng lên Map
        public void Draw(Point pt)
        {
            pt = new Point((int)pt.X,(int)pt.Y);
            Graphics g = Map.CreateGraphics();
            g.DrawImage(Img, pt);
            g.Dispose();
        }
        //Xóa đối tượng khỏi map
        public void Clear(Point pt)
        {
            pt = new Point(pt.X,pt.Y);
            Graphics g = Map.CreateGraphics();
            g.FillRectangle(new SolidBrush(Map_Const.Background), new Rectangle(pt, new Size(Map_Const.Width, Map_Const.Height)));
            g.DrawRectangle(new Pen(Map_Const.Grid_Color), new Rectangle(pt, new Size(Map_Const.Width, Map_Const.Height)));
            g.Dispose();
        }

    }
}
