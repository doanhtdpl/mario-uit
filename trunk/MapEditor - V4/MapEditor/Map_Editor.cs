using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace MapEditor
{
    public partial class Map_Editor : Form
    {
        #region Available

        //Khai báo biến
        Map_Info MapInfo;
        Map_Object Object;

        //Kiểm tra sự kiện mousedown
        bool IsMouseDown = false;
        Point LastMove;

        #endregion

        #region Map Event

        public Map_Editor()
        {
            InitializeComponent();
        }
        private void Map_Editor_Load(object sender, EventArgs e)
        {
            Map_Const.imgSelect = 0;
            //Khởi tạo thông tin map
            MapInfo = new Map_Info();
            NewMap(3000, 800);
            //Tạo 1 đối tượng trong map..Mặc định là player
            Object = new Map_Object(Img_List.Images[0], pn_Map);
            //Thiết lập màu của map
            pn_Map.BackColor = Map_Const.Background;
        }
        private void pn_Map_Paint(object sender, PaintEventArgs e)
        {
            DrawGrid();
        }

        
        //Sự kiện chuột đang giữ xuống
        private void pn_Map_MouseDown(object sender, MouseEventArgs e)
        {
            IsMouseDown = true;
        }

        //Sự kiện chuột đang buông
        private void pn_Map_MouseUp(object sender, MouseEventArgs e)
        {
            IsMouseDown = false;
        }

        //Sự kiện chuột di chuyển
        private void pn_Map_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.X < pn_Map.Width && e.Y < pn_Map.Height && e.X >= 0 && e.Y >= 0)
            {
                if (IsMouseDown && !IsPaint(new Point(e.X, e.Y)))
                {
                    pn_Map_MouseClick(sender, e);
                    LastMove = new Point(e.X, e.Y);
                }
            }
            
        }

        //Sự kiện chuột click
        private void pn_Map_MouseClick(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                MapInfo.Change(e.Location, (Map_Const.imgSelect + 1).ToString());
                Object.Clear(e.Location);
                Object.Draw(e.Location);
            }
            else
            {
                MapInfo.Change(e.Location, Map_Const.Default.ToString());
                Object.Clear(e.Location);
            }
        }

        //Sự kiện cho thanh cuộn
        private void hScrollBarMap_ValueChanged(object sender, EventArgs e)
        {
            hScrollBarMap.Maximum = Map_Const.X;
            pn_Map.Location = new Point(-hScrollBarMap.Value, pn_Map.Location.Y);


            if (hScrollBarMap.Value >= hScrollBarMap.Maximum - 800)
            {
                hScrollBarMap.Maximum += 200;
                AddMap(200, 0);
            }
        }
        private void hScrollBarMap_MouseCaptureChanged(object sender, EventArgs e)
        {
            DrawMap();
        }

        private void vScrollBarMap_ValueChanged(object sender, EventArgs e)
        {
            vScrollBarMap.Maximum = Map_Const.Y;
            pn_Map.Location = new Point(pn_Map.Location.X, -vScrollBarMap.Value);
            if (vScrollBarMap.Value >= vScrollBarMap.Maximum - 200)
            {
                vScrollBarMap.Maximum += 200;
                AddMap(0, 5);
            }

        }
        private void vScrollBarMap_MouseCaptureChanged(object sender, EventArgs e)
        {
            DrawMap();
        }


        #endregion

        #region Function

        //Kiểm tra ô nằm tọa độ e có được vẽ trong sự kiện mousemove chưa
        private bool IsPaint(Point e)
        {
            return ((e.X / Map_Const.Width) == (LastMove.X / Map_Const.Width) && (e.Y / Map_Const.Height) == (LastMove.Y / Map_Const.Height));
        }
        
        //Vẽ map từ Map_Info
        private void DrawMap()
        {
            for (int i = 0; i < Map_Const.X; i++)
            {
                for (int j = 0; j < Map_Const.Y; j++)
                {
                    if (MapInfo._Matrix[i, j] != Map_Const.Default.ToString())
                    {
                        Object = new Map_Object(Img_List.Images[(int.Parse(MapInfo._Matrix[i, j]) - 1)], pn_Map);
                        Object.Draw(new Point(i, j));
                    }
                }
            }

        }

        //Vẽ lưới cho map
        private void DrawGrid()
        {
            //Graphics g = pn_Map.CreateGraphics();
            //for (int i = 0; i < Map_Const.X; i++)
            //    for (int j = 0; j < Map_Const.Y; j++)
            //    {
            //        g.DrawRectangle(new Pen(Map_Const.Grid_Color), new Rectangle(new Point(i * Map_Const.Width, j * Map_Const.Height), new Size(Map_Const.Width, Map_Const.Height)));
            //    }
        }

        //Tại Map mới
        private void NewMap(int cols = 1, int rows = 1)
        {
            Map_Const.X = cols;
            Map_Const.Y = rows;
            pn_Map.Invalidate();
            pn_Map.Width = Map_Const.X;
            pn_Map.Height = Map_Const.Y;
            MapInfo.Load();
            hScrollBarMap.Value = 0;
            vScrollBarMap.Value = 0;
            pn_Map.Location = new Point(0, 0);
        }

        //Mở rộng Map
        private void AddMap(int cols, int rows)
        {
            MapInfo.Add(cols, rows);
            pn_Map.Invalidate();
            pn_Map.Width = Map_Const.X;
            pn_Map.Height = Map_Const.Y;
            DrawMap();
        }

        //Di Chuyển Map
        private void MoveLeft()
        {
            MapInfo.MoveLeft();
            DrawMap();
        }

        private void SelectPicture(int id_Picture)
        {
            Map_Const.imgSelect = id_Picture;
            Object = new Map_Object(Img_List.Images[id_Picture], pn_Map);
        }

        #endregion

        #region Button Event
        //Sự kiện click nút Mew
        private void btn_New_Click(object sender, EventArgs e)
        {
            NewMap newmap = new NewMap();
            newmap.ShowDialog();
            NewMap(newmap.cols, newmap.rows);
        }

        //Sự kiện click nút Add Map
        private void btnAddMap_Click(object sender, EventArgs e)
        {
            AddMap add = new AddMap();
            add.ShowDialog();
            if (add.cols == 0 && add.rows == 0) return;
            AddMap(add.cols, add.rows);
        }
        
        //Sự kiện click nút Moveleft
        private void btnMoveLeft_Click(object sender, EventArgs e)
        {
            MoveLeft();
            DrawMap();
        }

         //Sự kiện click nút Opent
        private void btn_Open_Click(object sender, EventArgs e)
        {
            OpenFileDialog frm = new OpenFileDialog();
            frm.Filter = "*.txt|*.txt";
          //  DialogResult dlg = //STAShowDialog(frm);
            frm.ShowDialog();
            if (frm.CheckPathExists)
            {
                NewMap();
                MapInfo.Open(frm.FileName);
                pn_Map.Width = Map_Const.X * Map_Const.Width;
                pn_Map.Height = Map_Const.Y * Map_Const.Height;
                DrawMap();
            }

        }

        //Sự kiện click nút Exit
        private void btn_Exit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        //Sự kiện click nút Save
        private void btn_Save_Click(object sender, EventArgs e)
        {
            MapInfo.Save();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SelectPicture(Int32.Parse(button1.Tag.ToString()));
        }

        private void button2_Click(object sender, EventArgs e)
        {
            SelectPicture(Int32.Parse(button2.Tag.ToString()));
        }

        private void button3_Click(object sender, EventArgs e)
        {
            SelectPicture(Int32.Parse(button3.Tag.ToString()));
        }

        private void button4_Click(object sender, EventArgs e)
        {
            SelectPicture(Int32.Parse(button4.Tag.ToString()));
        }

        #endregion

        

      
        
        
        
        
        
        
        

        

       
    }
}
