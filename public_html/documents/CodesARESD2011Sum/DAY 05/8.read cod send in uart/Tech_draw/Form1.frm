VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Begin VB.Form Form1 
   Caption         =   "Tech Draw"
   ClientHeight    =   4950
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   6795
   DrawWidth       =   10
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   87.313
   ScaleMode       =   6  'Millimeter
   ScaleWidth      =   119.856
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "start"
      Height          =   495
      Left            =   240
      TabIndex        =   3
      Top             =   3000
      Width           =   1215
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   240
      TabIndex        =   2
      Text            =   "1"
      Top             =   1800
      Width           =   1215
   End
   Begin VB.CommandButton Command3 
      Caption         =   "clear"
      Height          =   495
      Left            =   240
      TabIndex        =   1
      Top             =   3600
      Width           =   1215
   End
   Begin VB.PictureBox Picture1 
      DrawWidth       =   5
      Height          =   3375
      Left            =   1920
      ScaleHeight     =   221
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   293
      TabIndex        =   0
      Top             =   720
      Width           =   4455
   End
   Begin MSCommLib.MSComm MSComm1 
      Left            =   480
      Top             =   5520
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      DTREnable       =   -1  'True
      RThreshold      =   1
   End
   Begin VB.Label Label1 
      Caption         =   "COMM PORT"
      Height          =   495
      Left            =   360
      TabIndex        =   4
      Top             =   2400
      Width           =   1215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim x
Dim a, b
Private Sub Command1_Click()
x = 1
a = 1
b = 1
MSComm1.CommPort = Text1.Text
MSComm1.PortOpen = True

Picture1.Visible = True
Command3.Enabled = True
Command1.Enabled = False
End Sub

Private Sub Command2_Click()
Picture1.PSet (1, 1), vbRed
Picture1.PSet (2, 2), vbRed
Picture1.PSet (3, 3), vbRed
Picture1.PSet (4, 4), vbRed
Picture1.PSet (5, 5), vbRed
Picture1.PSet (6, 6), vbRed
Picture1.PSet (7, 7), vbRed
Picture1.PSet (8, 8), vbRed

End Sub

Private Sub Command3_Click()
Picture1.Picture = LoadPicture("")
End Sub

Private Sub Form_Load()
Picture1.Visible = False
Command3.Enabled = False
MsgBox "Assign a Commport Then click on start"
End Sub

Private Sub MSComm1_OnComm()
On Error Resume Next
Dim a
Dim x, y As Integer

a = MSComm1.Input
'Text1.Text = Left$(a, 3)
'Text2.Text = Right$(a, 3)
x = Left$(a, 3)
y = Right$(a, 3)

Picture1.PSet (Val(y), Val(x)), vbRed


End Sub
