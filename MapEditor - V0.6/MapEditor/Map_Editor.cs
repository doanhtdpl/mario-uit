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
        bool painted = false;
        bool IsMouseDown = false;
        bool IsShiftDown = false;
        Point LastPaint;

        #endregion

        #region Map Event

        public Map_Editor()
        {
            InitializeComponent();
        }

        private void Map_Editor_Load(object sender, EventArgs e)
        {
            txtValueMove.Text = "10";
            //Khởi tạo thông tin map
            MapInfo = new Map_Info();
            NewMap(1500, 700);
            //Tạo 1 đối tượng trong map..Mặc định là player
            Object = new Map_Object(Img_List.Images[0], pn_Map);
            //Thiết lập màu của map
            pn_Map.BackColor = Map_Info.Background;
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
            label1.Text = e.X + ", " + e.Y;
            if (e.X < pn_Map.Width && e.Y < pn_Map.Height && e.X >= 0 && e.Y >= 0)
            {
                if (IsMouseDown && !IsPaint(new Point(e.X, e.Y)))
                {
                    
                    if (IsShiftDown && e.Y>LastPaint.Y && e.Y<LastPaint.Y+Map_Info.Item_Height)
                    {
                        if (e.Button == MouseButtons.Left)
                        {
                            Point temp = new Point(e.X, LastPaint.Y);
                            MapInfo.Change(temp, (Map_Info.imgSelect).ToString());
                            Object.Clear(temp);
                            Object.Draw(temp);
                        }
                        LastPaint = new Point(e.X, LastPaint.Y);
                    }
                    else if (IsShiftDown && e.X > LastPaint.X && e.X < LastPaint.X + Map_Info.Item_Width)
                    {
                        if (e.Button == MouseButtons.Left)
                        {
                            Point temp = new Point(LastPaint.X, e.Y);
                            MapInfo.Change(temp, (Map_Info.imgSelect).ToString());
                            Object.Clear(temp);
                            Object.Draw(temp);
                        }
                        LastPaint = new Point(LastPaint.X, e.Y);
                    }
                    else
                    {
                        if (e.Button == MouseButtons.Left)
                        {
                            MapInfo.Change(e.Location, (Map_Info.imgSelect).ToString());
                            Object.Clear(e.Location);
                            Object.Draw(e.Location);
                        }
                        LastPaint = new Point(e.X, e.Y);
                    }
                    
                    painted = true;
                }
            }
        }

        //Sự kiện chuột click
        private void pn_Map_MouseClick(object sender, MouseEventArgs e)
        {
            if (!painted)
            {
                if (e.Button == MouseButtons.Left)
                {
                    MapInfo.Change(e.Location, (Map_Info.imgSelect).ToString());
                    Object.Clear(e.Location);
                    Object.Draw(e.Location);
                }
                LastPaint = new Point(e.X, e.Y);
               
            }
            painted = false;

        }

        private void Map_Editor_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.ShiftKey)
            {
                IsShiftDown = true;
               // MessageBox.Show("Shift Down");
            }
        }


        //Sự kiện cho thanh cuộn
        private void hScrollBarMap_ValueChanged(object sender, EventArgs e)
        {
            hScrollBarMap.Maximum = Map_Info.Width;
            pn_Map.Location = new Point(-hScrollBarMap.Value, pn_Map.Location.Y);


            if (hScrollBarMap.Value >= hScrollBarMap.Maximum - 900)
            {
                hScrollBarMap.Maximum += 100;
                AddMap(100, 0);
            }
        }
        private void hScrollBarMap_MouseCaptureChanged(object sender, EventArgs e)
        {
            DrawMap();
        }

        private void vScrollBarMap_ValueChanged(object sender, EventArgs e)
        {
            vScrollBarMap.Maximum = Map_Info.Height;
            pn_Map.Location = new Point(pn_Map.Location.X, -vScrollBarMap.Value);
            if (vScrollBarMap.Value >= vScrollBarMap.Maximum - 300)
            {
                vScrollBarMap.Maximum += 100;
                AddMap(0, 100);
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
            return ((e.X < (LastPaint.X + Map_Info.Item_Width)) && (e.X > (LastPaint.X - Map_Info.Item_Width))
                        && (e.Y < (LastPaint.Y + Map_Info.Item_Height)) && (e.Y > (LastPaint.Y - Map_Info.Item_Height)));
        }

        //Vẽ map từ Map_Info
        private void DrawMap()
        {
            foreach (string Obj in Map_Info.list_Object)
            {

                try
                {
                    string[] info_Object = Obj.Split(' ');
                    if (Map_Info.list_Object.IndexOf(Obj) > 1)
                    {
                        Object = new Map_Object(Img_List.Images[Int32.Parse(info_Object[0])], pn_Map);
                        Object.Draw(new Point(Int32.Parse(info_Object[1]), Int32.Parse(info_Object[2])));
                    }
                }
                catch
                {
                    MessageBox.Show("ERROR: Draw Map fail");
                }
            }

        }

        //Tại Map mới
        private void NewMap(int cols = 1, int rows = 1)
        {
            Map_Info.Width = cols;
            Map_Info.Height = rows;
            if (Map_Info.list_Object.Count > 0) Map_Info.list_Object.Clear();
            pn_Map.Invalidate();

            pn_Map.Width = Map_Info.Width;
            pn_Map.Height = Map_Info.Height;

            Map_Info.list_Object.Add("0");
            Map_Info.list_Object.Add("0");

            MapInfo.Clear();

            hScrollBarMap.Value = 0;
            vScrollBarMap.Value = 0;
            pn_Map.Location = new Point(0, 0);
        }



        //Mở rộng Map
        private void AddMap(int cols, int rows)
        {
            MapInfo.Add(cols, rows);
            pn_Map.Invalidate();
            pn_Map.Width = Map_Info.Width;
            pn_Map.Height = Map_Info.Height;
            DrawMap();
        }

        //Di Chuyển Map
        private void MoveLeft()
        {
            try
            {
                Int32.Parse(txtValueMove.Text);
                if (MapInfo.MoveLeft(Int32.Parse(txtValueMove.Text)))
                {
                    pn_Map.Invalidate();

                    pn_Map.Width = Map_Info.Width;
                    pn_Map.Height = Map_Info.Height;

                    //MapInfo.Clear();
                    //DrawMap();
                }
            }
            catch { }
        }

        private void SelectPicture(int id_Picture)
        {
            Map_Info.imgSelect = id_Picture;
            Object = new Map_Object(Img_List.Images[id_Picture], pn_Map);
        }

        #endregion

        #region Button Event
        //Sự kiện click nút Mew
        private void btn_New_Click(object sender, EventArgs e)
        {
            NewMap(1100, 650);
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
                pn_Map.Width = Map_Info.Width;
                pn_Map.Height = Map_Info.Height;
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

        private void btnMoveLeft_Click_1(object sender, EventArgs e)
        {
            MoveLeft();
            DrawMap();
        }

        

        private void Map_Editor_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.ShiftKey)
            {
                IsShiftDown = false;
              //  MessageBox.Show("Shift Up");
            }
        }





    }
}
