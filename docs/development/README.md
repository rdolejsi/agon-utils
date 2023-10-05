# Typical development tasks

---
**Table of contents**

- [Upgrading Gradle](#upgrading-gradle)

---

## Upgrading Gradle

Gradle uses wrapper to ensure it loads the right version of Gradle itself
to guarantee the compatibility with the project. To upgrade the Gradle version
in the project, feel free to use the following command (while changing the version):

```
./gradlew wrapper --gradle-version 8.3 --distribution-type all
```

_Please note: Gradle wrapper comes with platform-native scripts which might be
weird to commit at first sight, especially when any update of version changes
a lot of content in them. While one might personally hate that at first, over
the years of using Gradle, you'll find it more than convenient this ecosystem
can maintain itself and doesn't care about surrounding OS and its installed
packages._

_So: don't be afraid to commit changes in Unix and Windows shell scripts,
they are there for a good reason. And please, please, **don't change them in any way**._
