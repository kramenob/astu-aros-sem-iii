# Basement of algorithms and programming (SEM02)

Source code and docs.

---

## Init

---

## Progress

- [ ] Labs
  - [ ]
- [ ] Selfs
  - [ ] - [ ] diagram(-s)
    - [ ] report
- [ ] converting to .docx with formatting script

---

## Docs

Can be explore by .md + .drawio (for normal people) or converted to .docx for dinosaurs (with normal people support).

### TOC

- «Отчет самостоятельной работы №0» () // [~/docs/sels/00/report.md](docs/sels/00/report.md)

### Convert to .docx (Word)

Requirements from (docs/config/requirements):

- Pandoc
- librsvg
- gettext (`envsubst`)

Prepares:

- make executable scripts:

  `%`

  ```zsh
  chmod +x ./scripts/*.sh
  ```

Install dependencies:

- on macOS

  `%`

  ```zsh
  chmod +x ./scripts/install/macos.sh
  ./scripts/install/macos.sh
  ```

  Example tested on:

  `%`

  ```zsh
  pandoc 3.9.0.2
  Features: +server +lua
  Scripting engine: Lua 5.4

  rsvg-convert version 2.62.2
  ```

- on other platforms take pull request

Configuration:

Copy `docs/config/.env.example` to `docs/config/.env` and edit for Yourself.

Template variables may be used inside `.md` reports:

```md
${author}
${group}
${supervisor}
${year}
```

Add lab or sel template:

`%`

```zsh
chmod +x ./scripts/add/*.sh
./scripts/add/lab.sh
./scripts/add/sel.sh
```

Export reports:

`%`

```zsh
chmod +x ./scripts/export.sh
./scripts/export.sh
```

Output:

`>`

```zsh
Generated: ~/docs/scripts/../output/0*.docx
...
```

---

Copyright (c) 2026 Maksim Bolotin (publicly known as Mark Bone) (github.com/kramenob)

All rights reserved.

This software and associated documentation files may not be copied, modified,
distributed, used, or incorporated into other works without explicit written
permission from the author.
