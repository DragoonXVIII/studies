using Newtonsoft.Json;
using System.Net.Http;
using System.Text;
using System.Windows.Forms;
using System;

namespace lab8
{
    partial class Form1
    {

        /// <summary>
        /// Wymagana zmienna projektanta.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Wyczyść wszystkie używane zasoby.
        /// </summary>
        /// <param name="disposing">prawda, jeżeli zarządzane zasoby powinny zostać zlikwidowane; Fałsz w przeciwnym wypadku.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Kod generowany przez Projektanta formularzy systemu Windows

        /// <summary>
        /// Metoda wymagana do obsługi projektanta — nie należy modyfikować
        /// jej zawartości w edytorze kodu.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.txtUsername = new System.Windows.Forms.TextBox();
            this.txtPassword = new System.Windows.Forms.TextBox();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.btnLogin = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.btnGetUserCount = new System.Windows.Forms.Button();
            this.btnGetPrimeNumber = new System.Windows.Forms.Button();
            this.btnGetUserList = new System.Windows.Forms.Button();
            this.rtbToken = new System.Windows.Forms.RichTextBox();
            this.rtbData = new System.Windows.Forms.RichTextBox();
            this.richTextBox2 = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // txtUsername
            // 
            this.txtUsername.Location = new System.Drawing.Point(114, 37);
            this.txtUsername.Name = "txtUsername";
            this.txtUsername.Size = new System.Drawing.Size(100, 22);
            this.txtUsername.TabIndex = 0;
            // 
            // txtPassword
            // 
            this.txtPassword.Location = new System.Drawing.Point(114, 65);
            this.txtPassword.Name = "txtPassword";
            this.txtPassword.PasswordChar = '*';
            this.txtPassword.Size = new System.Drawing.Size(100, 22);
            this.txtPassword.TabIndex = 1;
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(35, 40);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(73, 16);
            this.label1.TabIndex = 3;
            this.label1.Text = "Username:";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(35, 68);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(70, 16);
            this.label2.TabIndex = 4;
            this.label2.Text = "Password:";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // btnLogin
            // 
            this.btnLogin.Location = new System.Drawing.Point(127, 93);
            this.btnLogin.Name = "btnLogin";
            this.btnLogin.Size = new System.Drawing.Size(75, 30);
            this.btnLogin.TabIndex = 5;
            this.btnLogin.Text = "Login";
            this.btnLogin.UseVisualStyleBackColor = true;
            this.btnLogin.Click += new System.EventHandler(this.btnLogin_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(35, 142);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(49, 16);
            this.label3.TabIndex = 6;
            this.label3.Text = "Token:";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // btnGetUserCount
            // 
            this.btnGetUserCount.Location = new System.Drawing.Point(290, 15);
            this.btnGetUserCount.Name = "btnGetUserCount";
            this.btnGetUserCount.Size = new System.Drawing.Size(112, 34);
            this.btnGetUserCount.TabIndex = 8;
            this.btnGetUserCount.Text = "getUserCount()";
            this.btnGetUserCount.UseVisualStyleBackColor = true;
            this.btnGetUserCount.Click += new System.EventHandler(this.btnGetUserCount_Click);
            // 
            // btnGetPrimeNumber
            // 
            this.btnGetPrimeNumber.Location = new System.Drawing.Point(284, 68);
            this.btnGetPrimeNumber.Name = "btnGetPrimeNumber";
            this.btnGetPrimeNumber.Size = new System.Drawing.Size(128, 32);
            this.btnGetPrimeNumber.TabIndex = 9;
            this.btnGetPrimeNumber.Text = "getPrimeNumber()";
            this.btnGetPrimeNumber.UseVisualStyleBackColor = true;
            this.btnGetPrimeNumber.Click += new System.EventHandler(this.btnGetPrimeNumber_Click);
            // 
            // btnGetUserList
            // 
            this.btnGetUserList.Location = new System.Drawing.Point(290, 117);
            this.btnGetUserList.Name = "btnGetUserList";
            this.btnGetUserList.Size = new System.Drawing.Size(112, 28);
            this.btnGetUserList.TabIndex = 10;
            this.btnGetUserList.Text = "getUserList()";
            this.btnGetUserList.UseVisualStyleBackColor = true;
            this.btnGetUserList.Click += new System.EventHandler(this.btnGetUsersList_Click);
            // 
            // rtbToken
            // 
            this.rtbToken.Location = new System.Drawing.Point(38, 173);
            this.rtbToken.Name = "rtbToken";
            this.rtbToken.ReadOnly = true;
            this.rtbToken.Size = new System.Drawing.Size(374, 45);
            this.rtbToken.TabIndex = 15;
            this.rtbToken.Text = "";
            this.rtbToken.TextChanged += new System.EventHandler(this.richTextBox1_TextChanged);
            // 
            // rtbData
            // 
            this.rtbData.Location = new System.Drawing.Point(38, 238);
            this.rtbData.Name = "rtbData";
            this.rtbData.Size = new System.Drawing.Size(176, 200);
            this.rtbData.TabIndex = 16;
            this.rtbData.Text = "";
            // 
            // richTextBox2
            // 
            this.richTextBox2.Location = new System.Drawing.Point(236, 238);
            this.richTextBox2.Name = "richTextBox2";
            this.richTextBox2.Size = new System.Drawing.Size(176, 200);
            this.richTextBox2.TabIndex = 17;
            this.richTextBox2.Text = "";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(468, 450);
            this.Controls.Add(this.richTextBox2);
            this.Controls.Add(this.rtbData);
            this.Controls.Add(this.rtbToken);
            this.Controls.Add(this.btnGetUserList);
            this.Controls.Add(this.btnGetPrimeNumber);
            this.Controls.Add(this.btnGetUserCount);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.btnLogin);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtPassword);
            this.Controls.Add(this.txtUsername);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtUsername;
        private System.Windows.Forms.TextBox txtPassword;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btnLogin;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button btnGetUserCount;
        private System.Windows.Forms.Button btnGetPrimeNumber;
        private System.Windows.Forms.Button btnGetUserList;
        private RichTextBox rtbToken;
        private RichTextBox rtbData;
        private RichTextBox richTextBox2;
    }
}

