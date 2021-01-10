{
  "targets": [
    {
      "target_name": "LeftTrim",
      "sources": [ "/src/LeftTrim.cpp" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
