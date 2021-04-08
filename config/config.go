// This file was generated from JSON Schema using quicktype, do not modify it directly.
// To parse and unparse this JSON data, add this code to your project and do:
//
//    config, err := UnmarshalConfig(bytes)
//    bytes, err = config.Marshal()

package config

import (
	"encoding/json"
	"io/ioutil"
)

func Load(filename string) (config *Config, err error) {
	var configJSONData []byte
	configJSONData, err = ioutil.ReadFile(filename)
	if err != nil {
		return nil, err
	}
	config, err = UnmarshalConfig(configJSONData)
	return
}

func UnmarshalConfig(data []byte) (*Config, error) {
	r := &Config{}
	err := json.Unmarshal(data, &r)
	return r, err
}

func (r *Config) Marshal() ([]byte, error) {
	return json.Marshal(r)
}

type Config struct {
	Keyboards []Keyboard `json:"keyboards"`
}

func (cfg *Config) FindKeyboard(kb_name string) (kb *Keyboard) {
	for _, k := range cfg.Keyboards {
		if kb_name == k.Name {
			return &k
		}
	}
	return nil
}

type Keyboard struct {
	Name    string    `json:"name"`
	Numkeys int64     `json:"numkeys"`
	Rows    [][]int64 `json:"rows"`
	Viz     []string  `json:"viz"`
}
