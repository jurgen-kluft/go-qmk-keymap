package svg

import (
	"fmt"
	"strings"
)

var STYLE = `
    svg {
        font-family: SFMono-Regular,Consolas,Liberation Mono,Menlo,monospace;
        font-size: 14px;
        font-kerning: normal;
        text-rendering: optimizeLegibility;
        fill: #34393e;
        font-weight: bold;
    }

    rect {
        fill: #f6f8fa;
    }

    .layertitle { 
        font-weight: bold;
        font-size: 16px; 
		fill: #F30000; 
	}

    .green {
        fill: #fdd;
    }

    .green {
        fill: #dfd;
    }

    .purple {
        fill: #ddf;
    }

    .yellow {
        fill: #ffd;
    }

    .blue {
        fill: #dff;
    }

    .pink {
        fill: #fdf;
    }

    .grey {
        fill: #ddd;
    }

    .red {
        fill: #fdd;
    }

    .none {
        fill: #fff;
        fill-opacity: 0.0;
    }
`

type instance struct {
	lines []string

	KeyW        int
	KeyH        int
	KeyRx       int
	KeyRy       int
	InnerPadW   int
	InnerPadH   int
	OuterPadW   int
	OuterPadH   int
	LineSpacing int
	KeyspaceW   int
	KeyspaceH   int
	HandW       int
	HandH       int
	LayerW      int
	LayerH      int
	BoardW      int
	BoardH      int
}

type Key_t struct {
	Exists bool
	Key    string
	Class  string
}

// Kyria one hand is 8 keys wide and 4 keys high, so in total the matrix is 16x4.
// Some keys are marked as exists=false to indicate that they do not exist and
// should not be printed.

type Layer_t struct {
	Name   string
	Matrix [][]Key_t
}

// begin svg
func Print(layers []Layer_t) []string {
	s := &instance{}
	s.KeyW = 55
	s.KeyH = 45
	s.KeyRx = 6
	s.KeyRy = 6
	s.InnerPadW = 2
	s.InnerPadH = 2
	s.OuterPadW = s.KeyW / 2
	s.OuterPadH = s.KeyH / 2
	s.LineSpacing = 18

	s.KeyspaceW = s.KeyW + 2*s.InnerPadW
	s.KeyspaceH = s.KeyH + 2*s.InnerPadH
	s.HandW = 8 * s.KeyspaceW
	s.HandH = 4 * s.KeyspaceH
	s.LayerW = 2*s.HandW + s.KeyspaceW + s.OuterPadW
	s.LayerH = s.HandH
	s.BoardW = s.LayerW + 2*s.OuterPadW
	s.BoardH = s.KeyH + len(layers)*(s.LayerH+s.OuterPadH+s.KeyspaceH)

	s.lines = []string{}
	s.lines = append(s.lines, "<svg width=\""+fmt.Sprintf("%d", s.BoardW)+"\" height=\""+fmt.Sprintf("%d", s.BoardH)+"\" viewBox=\"0 0 "+fmt.Sprintf("%d", s.BoardW)+" "+fmt.Sprintf("%d", s.BoardH)+"\" xmlns=\"http://www.w3.org/2000/svg\">")
	s.lines = append(s.lines, "<style>")
	s.lines = append(s.lines, STYLE)
	s.lines = append(s.lines, "</style>")

	s.print_layers(layers)

	s.lines = append(s.lines, "</svg>")
	return s.lines
}

func (s *instance) print_key(x int, y int, key Key_t) {

	line := fmt.Sprintf("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" rx=\"%d\" ry=\"%d\" class=\"%s\" />", x+s.InnerPadW, y+s.InnerPadH, s.KeyW, s.KeyH, s.KeyRx, s.KeyRy, key.Class)
	s.lines = append(s.lines, line)

	words := strings.Split(key.Key, " ")
	y += (s.KeyspaceH - (len(words)-1)*s.LineSpacing) / 2
	for _, word := range words {
		line = fmt.Sprintf("<text x=\"%d\" y=\"%d\" text-anchor=\"middle\" class=\"key-text\">%s</text>", x+s.KeyspaceW/2, y, word)
		s.lines = append(s.lines, line)
		y += s.LineSpacing
	}
}

func (s *instance) print_layer(x int, y int, layer Layer_t) {
	for r, row := range layer.Matrix {
		for k, key := range row {
			if key.Exists {
				s.print_key(x+k*s.KeyspaceW, y+r*s.KeyspaceH, key)
			}
		}
	}
}

func (s *instance) print_layers(layers []Layer_t) {
	x := s.OuterPadW
	y := s.LineSpacing + s.OuterPadH

	for _, layer := range layers {

		line := fmt.Sprintf("<text x=\"%d\" y=\"%d\" text-anchor=\"left\" class=\"layertitle\">%s</text>", x, y-s.LineSpacing, layer.Name)
		s.lines = append(s.lines, line)

		s.print_layer(x, y, layer)
		y += s.LayerH + s.OuterPadH + s.KeyspaceH
	}
}
