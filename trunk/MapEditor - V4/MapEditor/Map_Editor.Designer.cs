﻿namespace MapEditor
{
    partial class Map_Editor
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Map_Editor));
            this.Img_List = new System.Windows.Forms.ImageList(this.components);
            this.btn_New = new System.Windows.Forms.Button();
            this.btn_Open = new System.Windows.Forms.Button();
            this.btn_Save = new System.Windows.Forms.Button();
            this.btn_Exit = new System.Windows.Forms.Button();
            this.pn_Map = new System.Windows.Forms.Panel();
            this.pnMap = new System.Windows.Forms.Panel();
            this.vScrollBarMap = new System.Windows.Forms.VScrollBar();
            this.hScrollBarMap = new System.Windows.Forms.HScrollBar();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.pnMap.SuspendLayout();
            this.SuspendLayout();
            // 
            // Img_List
            // 
            this.Img_List.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("Img_List.ImageStream")));
            this.Img_List.TransparentColor = System.Drawing.Color.Transparent;
            this.Img_List.Images.SetKeyName(0, "BIG_PIPE.png");
            this.Img_List.Images.SetKeyName(1, "BIG_TREE.png");
            this.Img_List.Images.SetKeyName(2, "BRICK.png");
            this.Img_List.Images.SetKeyName(3, "CLOUD.png");
            this.Img_List.Images.SetKeyName(4, "COIN.png");
            this.Img_List.Images.SetKeyName(5, "END_COLUMN.png");
            this.Img_List.Images.SetKeyName(6, "END_MARK.png");
            this.Img_List.Images.SetKeyName(7, "FENCE.png");
            this.Img_List.Images.SetKeyName(8, "FLOWER.png");
            this.Img_List.Images.SetKeyName(9, "GRASS.png");
            this.Img_List.Images.SetKeyName(10, "LAND.png");
            this.Img_List.Images.SetKeyName(11, "LARGER.png");
            this.Img_List.Images.SetKeyName(12, "LIFEUP.png");
            this.Img_List.Images.SetKeyName(13, "MEDIUM_PIPE.png");
            this.Img_List.Images.SetKeyName(14, "MOUNTAIN.png");
            this.Img_List.Images.SetKeyName(15, "MUSHROOM.png");
            this.Img_List.Images.SetKeyName(16, "MUSHROOM_LEFT.png");
            this.Img_List.Images.SetKeyName(17, "PipeBig.png");
            this.Img_List.Images.SetKeyName(18, "SINGLECOIN.png");
            this.Img_List.Images.SetKeyName(19, "SMALL_PIPE.png");
            this.Img_List.Images.SetKeyName(20, "SMALL_TREE.png");
            this.Img_List.Images.SetKeyName(21, "Test.png");
            this.Img_List.Images.SetKeyName(22, "TURTLE.png");
            // 
            // btn_New
            // 
            this.btn_New.Location = new System.Drawing.Point(1097, 14);
            this.btn_New.Name = "btn_New";
            this.btn_New.Size = new System.Drawing.Size(75, 23);
            this.btn_New.TabIndex = 5;
            this.btn_New.Text = "New";
            this.btn_New.UseVisualStyleBackColor = true;
            this.btn_New.Click += new System.EventHandler(this.btn_New_Click);
            // 
            // btn_Open
            // 
            this.btn_Open.Location = new System.Drawing.Point(1097, 43);
            this.btn_Open.Name = "btn_Open";
            this.btn_Open.Size = new System.Drawing.Size(75, 23);
            this.btn_Open.TabIndex = 6;
            this.btn_Open.Text = "Open";
            this.btn_Open.UseVisualStyleBackColor = true;
            this.btn_Open.Click += new System.EventHandler(this.btn_Open_Click);
            // 
            // btn_Save
            // 
            this.btn_Save.Location = new System.Drawing.Point(1097, 76);
            this.btn_Save.Name = "btn_Save";
            this.btn_Save.Size = new System.Drawing.Size(75, 23);
            this.btn_Save.TabIndex = 7;
            this.btn_Save.Text = "Save";
            this.btn_Save.UseVisualStyleBackColor = true;
            this.btn_Save.Click += new System.EventHandler(this.btn_Save_Click);
            // 
            // btn_Exit
            // 
            this.btn_Exit.Location = new System.Drawing.Point(1097, 108);
            this.btn_Exit.Name = "btn_Exit";
            this.btn_Exit.Size = new System.Drawing.Size(75, 23);
            this.btn_Exit.TabIndex = 8;
            this.btn_Exit.Text = "Exit";
            this.btn_Exit.UseVisualStyleBackColor = true;
            this.btn_Exit.Click += new System.EventHandler(this.btn_Exit_Click);
            // 
            // pn_Map
            // 
            this.pn_Map.AllowDrop = true;
            this.pn_Map.Location = new System.Drawing.Point(0, 0);
            this.pn_Map.Name = "pn_Map";
            this.pn_Map.Size = new System.Drawing.Size(100, 50);
            this.pn_Map.TabIndex = 0;
            this.pn_Map.Paint += new System.Windows.Forms.PaintEventHandler(this.pn_Map_Paint);
            this.pn_Map.MouseClick += new System.Windows.Forms.MouseEventHandler(this.pn_Map_MouseClick);
            this.pn_Map.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pn_Map_MouseDown);
            this.pn_Map.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pn_Map_MouseMove);
            this.pn_Map.MouseUp += new System.Windows.Forms.MouseEventHandler(this.pn_Map_MouseUp);
            // 
            // pnMap
            // 
            this.pnMap.Controls.Add(this.vScrollBarMap);
            this.pnMap.Controls.Add(this.hScrollBarMap);
            this.pnMap.Controls.Add(this.pn_Map);
            this.pnMap.Location = new System.Drawing.Point(12, 14);
            this.pnMap.Name = "pnMap";
            this.pnMap.Size = new System.Drawing.Size(1062, 455);
            this.pnMap.TabIndex = 1165;
            // 
            // vScrollBarMap
            // 
            this.vScrollBarMap.Dock = System.Windows.Forms.DockStyle.Right;
            this.vScrollBarMap.LargeChange = 100;
            this.vScrollBarMap.Location = new System.Drawing.Point(1045, 0);
            this.vScrollBarMap.Name = "vScrollBarMap";
            this.vScrollBarMap.Size = new System.Drawing.Size(17, 438);
            this.vScrollBarMap.SmallChange = 50;
            this.vScrollBarMap.TabIndex = 2436;
            this.vScrollBarMap.ValueChanged += new System.EventHandler(this.vScrollBarMap_ValueChanged);
            this.vScrollBarMap.MouseCaptureChanged += new System.EventHandler(this.vScrollBarMap_MouseCaptureChanged);
            // 
            // hScrollBarMap
            // 
            this.hScrollBarMap.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.hScrollBarMap.LargeChange = 100;
            this.hScrollBarMap.Location = new System.Drawing.Point(0, 438);
            this.hScrollBarMap.Name = "hScrollBarMap";
            this.hScrollBarMap.Size = new System.Drawing.Size(1062, 17);
            this.hScrollBarMap.SmallChange = 50;
            this.hScrollBarMap.TabIndex = 1;
            this.hScrollBarMap.ValueChanged += new System.EventHandler(this.hScrollBarMap_ValueChanged);
            this.hScrollBarMap.MouseCaptureChanged += new System.EventHandler(this.hScrollBarMap_MouseCaptureChanged);
            // 
            // button1
            // 
            this.button1.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button1.BackgroundImage")));
            this.button1.Location = new System.Drawing.Point(1097, 397);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 67);
            this.button1.TabIndex = 1166;
            this.button1.Tag = "2";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button2.BackgroundImage")));
            this.button2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.button2.Location = new System.Drawing.Point(1097, 311);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 67);
            this.button2.TabIndex = 1166;
            this.button2.Tag = "3";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button3.BackgroundImage")));
            this.button3.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.button3.Location = new System.Drawing.Point(1097, 224);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(75, 67);
            this.button3.TabIndex = 1166;
            this.button3.Tag = "9";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            // 
            this.button4.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button4.BackgroundImage")));
            this.button4.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button4.Location = new System.Drawing.Point(1097, 137);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(75, 67);
            this.button4.TabIndex = 1166;
            this.button4.Tag = "10";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // Map_Editor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.ClientSize = new System.Drawing.Size(1184, 490);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.pnMap);
            this.Controls.Add(this.btn_Exit);
            this.Controls.Add(this.btn_Save);
            this.Controls.Add(this.btn_Open);
            this.Controls.Add(this.btn_New);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Map_Editor";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Map Editor";
            this.Load += new System.EventHandler(this.Map_Editor_Load);
            this.pnMap.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ImageList Img_List;
        private System.Windows.Forms.Button btn_New;
        private System.Windows.Forms.Button btn_Open;
        private System.Windows.Forms.Button btn_Save;
        private System.Windows.Forms.Button btn_Exit;
        public System.Windows.Forms.Panel pn_Map;
        private System.Windows.Forms.Panel pnMap;
        private System.Windows.Forms.VScrollBar vScrollBarMap;
        private System.Windows.Forms.HScrollBar hScrollBarMap;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
    }
}