using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing;
using System.IO;

namespace MapEditor
{
    class Map_Info
    {
        private string[,] Matrix;
        private string[,] Temp;

        public string[,] _Matrix
        {
            get { return Matrix; }
            set { Matrix = value; }
        }

        //Khởi tạo giá trị mặc định cho ma trận
        public void Load()
        {
            Matrix = new string[Map_Const.X, Map_Const.Y];
            for (int i = 0; i < Map_Const.X; i++)
                for (int j = 0; j < Map_Const.Y; j++)
                    Matrix[i, j] = Map_Const.Default.ToString();
        }

        //Mở rộng Map
        public void Add(int cols, int rows)
        {
            Temp = Matrix;
            Matrix = new string[Map_Const.X + cols, Map_Const.Y + rows];

            //gán tất cả giá trị là 0
            for (int i = 0; i < Map_Const.X + cols; i++)
                for (int j = 0; j < Map_Const.Y + rows; j++)
                {
                    Matrix[i, j] = Map_Const.Default.ToString();
                }
            //danh dau cac vi tri ve
            for (int i = 0; i < Map_Const.X; i++)
                for (int j = 0; j < Map_Const.Y; j++)
                {
                    Matrix[i, j] = Temp[i, j];
                }

            Temp = null;
            Map_Const.X += cols;
            Map_Const.Y += rows;
        }

        //di chuyen sang trai
        public void MoveLeft()
        {
            
            for (int i = 0; i < Map_Const.Y; i++)
            {
                if (Matrix[0, i] != Map_Const.Default.ToString())
                {
                    MessageBox.Show("Can't Move");
                    return;
                }
            }

            for (int i = 1; i < Map_Const.X; i++)
                for (int j = 0; j < Map_Const.Y; j++)
                {
                    Matrix[Map_Const.X - 1, j] = Map_Const.Default.ToString();
                    if (Matrix[i, j] != Map_Const.Default.ToString())
                    {
                        Matrix[i - 1, j] = Matrix[i, j];
                        Matrix[i, j] = Map_Const.Default.ToString();
                    }
                }
        }

        //Thay đổi giá trị một phần tử của ma trận
        public void Change(Point pt, string str)
        {
            Matrix[pt.X, pt.Y] = str;

            if (pt.X > Map_Const.Map_Width) Map_Const.Map_Width = pt.X;
            if (pt.Y > Map_Const.Map_Height) Map_Const.Map_Height = pt.Y;
        }

        //Đọc Map
        public void Open(string filename)
        {
            string[] valueLine;
            int line = 0, count = 0;

            StreamReader sr = new StreamReader(filename);
            string str = sr.ReadLine();
            while (str != null)
            {
                line++;
                str = sr.ReadLine();
            }

            valueLine = new string[line];
            sr = new StreamReader(filename);
            str = sr.ReadLine();
            while (str != null)
            {
                valueLine[count++] = str;
                str = sr.ReadLine();
            }
            sr.Close();
            sr.Dispose();

            try
            {
                Map_Const.X = Int32.Parse(valueLine[0].Split(' ')[0]);
                //if (Map_Const.X < 1500) Map_Const.X = 1500;
                Map_Const.Y = Int32.Parse(valueLine[1].Split(' ')[0]);
                //if (Map_Const.Y < 455) Map_Const.Y = 455;
            }
            catch (Exception)
            {
                MessageBox.Show("This is not file Map");
                return;
            }

            Matrix = new string[Map_Const.X, Map_Const.Y];

            for (int i = 0; i < Map_Const.X; i++)
                for (int j = 0; j < Map_Const.Y; j++)
                {
                    Matrix[i, j] = Map_Const.Default.ToString();
                }

            string[] valueObject;
            for (int i = 2; i < line; i++)
            {
                if (valueLine[i] == null) break;
                valueObject = valueLine[i].Split(' ');
                Matrix[Int32.Parse(valueObject[1]), Int32.Parse(valueObject[2])] = valueObject[0];
            }
        }

        //Lưu Map
        public void Save()
        {
            try
            {
                SaveFileDialog saveFileDlg = new SaveFileDialog();
                saveFileDlg.InitialDirectory = Application.ExecutablePath;
                saveFileDlg.Filter = "all file (*.txt)|*.txt";
                if (saveFileDlg.ShowDialog() == DialogResult.OK)
                {
                    FileStream fs = new FileStream(saveFileDlg.FileName, FileMode.Create);
                    StreamWriter sw = new StreamWriter(fs);
                    int count = 2;
                     
                    string[] valuewrite = new string[Map_Const.X * Map_Const.Y + 2];
                    valuewrite[0] = (Map_Const.Map_Width + Map_Const.Item_Width).ToString();
                    valuewrite[1] = (Map_Const.Map_Height + Map_Const.Item_Height).ToString();
                    for (int i = 0; i < Map_Const.X; i++)
                        for (int j = 0; j < Map_Const.Y; j++)
                        {
                            if (Matrix[i, j] != Map_Const.Default.ToString())
                            {
                                valuewrite[count++] = Matrix[i, j] + " " + i.ToString() + " " + j.ToString();
                            }
                        }
                    foreach (string valueline in valuewrite)
                    {
                        if (valueline == null) break;
                        sw.WriteLine(valueline);
                    }
                    sw.Flush();
                    sw.Close();
                    fs.Close();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}

