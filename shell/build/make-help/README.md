


**come from https://gitlab.com/depressiveRobot/make-help**

# Make Help

[![license](https://img.shields.io/badge/license-MIT-green.svg)](https://opensource.org/licenses/MIT)
[![readme style](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg)](https://github.com/RichardLitt/standard-readme)

> A simple help dialog for Makefiles.

A [Makefile](https://www.gnu.org/software/make/) enables people to manage a project without knowing how it works in detail.
It is the entry point to the project code.
By providing a `help` target it makes it even easier for people to use the project.

## Table of Contents

* [Install](#install)
* [Usage](#usage)
* [Badge](#badge)
* [License](#license)

## Install

Print the `help` target to your console:

```bash
curl -s https://gitlab.com/depressiveRobot/make-help/raw/master/help.mk
```

Alternatively, use this command to create a ready-to-use Makefile in your project folder:

```bash
wget https://gitlab.com/depressiveRobot/make-help/raw/master/examples/Makefile
```

This Makefile has the `help` target set as default target. Just enter `make` and it will print the help dialog.

## Usage

Add a line starting with `##` in front of a target in order to see it in the help dialog:

```make
## The help message
foo:
  @echo "A documented target"
```

This will add an entry of the target to the help dialog:

```bash
$ make help
Available targets:

  foo                  The help message
  help                 Show this help
```

**Note:** Targets with a conventional comment (`#`) are not displayed in the help dialog.

## Badge

If you use this `help` target in your Makefile, you can use this badge to link back to this project:

[![make help](https://img.shields.io/badge/make-help-brightgreen.svg)](https://gitlab.com/depressiveRobot/make-help)

Use this code to add it to your Markdown file:

```md
[![make help](https://img.shields.io/badge/make-help-brightgreen.svg)](https://gitlab.com/depressiveRobot/make-help)
```

## License

[MIT](https://opensource.org/licenses/MIT) © Marvin Frommhold

See license in [LICENSE.txt](./LICENSE.txt)
