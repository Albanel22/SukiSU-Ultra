// SPDX-License-Identifier: GPL-2.0
/*
 * Stubs pour compat noyau 4.19 : fonctions déclarées mais dont l'implémentation
 * réelle a été exclue de la compilation car elle dépend de structures internes
 * (struct selinux_policy, struct seccomp_filter.cache) introduites dans des
 * versions de noyau bien plus récentes que 4.19.
 *
 * - ksu_selinux_hide_* : provenaient de feature/selinux_hide.c (exclu du Kbuild)
 * - apply_kernelsu_rules / handle_sepolicy : provenaient de selinux/rules.c (exclu)
 * - ksu_seccomp_allow_cache : provenait de infra/seccomp_cache.c (exclu)
 *
 * ATTENTION : apply_kernelsu_rules() est stubée en no-op. Si SELinux est en
 * mode enforcing, le domaine ksu peut se retrouver sans les règles d'accès
 * nécessaires. À surveiller lors du premier test sur téléphone.
 */

#include <linux/errno.h>
#include <linux/types.h>
#include <linux/uaccess.h>

struct seccomp_filter;

void ksu_selinux_hide_init(void)
{
}

void ksu_selinux_hide_exit(void)
{
}

void ksu_selinux_hide_drop_backup_if_unused(void)
{
}

void ksu_selinux_hide_handle_second_stage(void)
{
}

void ksu_selinux_hide_handle_post_fs_data(void)
{
}

void apply_kernelsu_rules(void)
{
    /* no-op : voir l'avertissement en tête de fichier */
}

int handle_sepolicy(void __user *user_data, u64 data_len)
{
    return -EOPNOTSUPP;
}

void ksu_seccomp_allow_cache(struct seccomp_filter *filter, int nr)
{
}
