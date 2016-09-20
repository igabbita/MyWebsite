VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Begin VB.Form Form1 
   BackColor       =   &H80000009&
   Caption         =   "Form1"
   ClientHeight    =   9210
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7485
   LinkTopic       =   "Form1"
   ScaleHeight     =   9210
   ScaleWidth      =   7485
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Select CommPort"
      Height          =   495
      Left            =   6000
      TabIndex        =   9
      Top             =   7680
      Width           =   1215
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   6000
      TabIndex        =   8
      Text            =   "1"
      Top             =   7200
      Width           =   1215
   End
   Begin MSCommLib.MSComm MSComm1 
      Left            =   0
      Top             =   8640
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      DTREnable       =   -1  'True
   End
   Begin VB.CommandButton stops 
      BackColor       =   &H80000001&
      Caption         =   "stop"
      Height          =   1815
      Index           =   4
      Left            =   2640
      TabIndex        =   7
      Top             =   4800
      Width           =   2055
   End
   Begin VB.CommandButton backword 
      BackColor       =   &H80000001&
      Caption         =   "backword"
      Height          =   1815
      Index           =   3
      Left            =   2640
      TabIndex        =   6
      Top             =   6840
      Width           =   2055
   End
   Begin VB.CommandButton lefts 
      BackColor       =   &H80000001&
      Caption         =   "left"
      Height          =   1815
      Index           =   2
      Left            =   360
      TabIndex        =   5
      Top             =   4800
      Width           =   2055
   End
   Begin VB.CommandButton right 
      BackColor       =   &H80000001&
      Caption         =   "right"
      Height          =   1815
      Index           =   1
      Left            =   4920
      TabIndex        =   4
      Top             =   4800
      Width           =   2055
   End
   Begin VB.CommandButton forward 
      BackColor       =   &H80000001&
      Caption         =   "forward"
      Height          =   1815
      Index           =   0
      Left            =   2640
      TabIndex        =   3
      Top             =   2760
      Width           =   2055
   End
   Begin VB.PictureBox Picture1 
      BackColor       =   &H80000009&
      Height          =   1455
      Left            =   1440
      Picture         =   "Form1.frx":0000
      ScaleHeight     =   1395
      ScaleWidth      =   4755
      TabIndex        =   1
      Top             =   120
      Width           =   4815
   End
   Begin VB.Label Label1 
      BackColor       =   &H00FFFFFF&
      Caption         =   "www.technophilia.co.in"
      Height          =   255
      Left            =   5520
      TabIndex        =   2
      Top             =   8880
      Width           =   1815
   End
   Begin VB.Label Label2 
      BackColor       =   &H80000009&
      Caption         =   "ROBOTIC CONTROL STATION"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   24
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   975
      Left            =   120
      TabIndex        =   0
      Top             =   1680
      Width           =   7575
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False


Private Sub Command1_Click()
MSComm1.CommPort = Text1.Text
MSComm1.PortOpen = True

forward(0).Visible = True
backword(3).Visible = True
stops(4).Visible = True
lefts(2).Visible = True
right(1).Visible = True
Command1.Enabled = False

End Sub

Private Sub Form_Load()
forward(0).Visible = False
backword(3).Visible = False
stops(4).Visible = False
lefts(2).Visible = False
right(1).Visible = False

End Sub

Private Sub forward_Click(Index As Integer)
MSComm1.Output = "F"
End Sub
Private Sub stops_Click(Index As Integer)
MSComm1.Output = "S"
End Sub
Private Sub backword_Click(Index As Integer)
MSComm1.Output = "B"
End Sub

Private Sub lefts_Click(Index As Integer)
MSComm1.Output = "L"
End Sub

Private Sub right_Click(Index As Integer)
MSComm1.Output = "R"
End Sub


